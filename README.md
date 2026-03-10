# mps2-rt — ARM Cortex-M Bare-Metal Runtime

[![CI](https://github.com/kriskwiatkowski/runtime_mps2/actions/workflows/ci.yml/badge.svg)](https://github.com/kriskwiatkowski/runtime_mps2/actions/workflows/ci.yml)

Bare-metal runtime for ARM MPS2 platforms. Provides everything needed to build, run, and test cryptographic algorithms — including hand-written assembly — on ARMv7-M and ARMv8-M cores using QEMU, with no physical hardware required.

Designed for research and early-stage development: integrate `libmps2rtm.a` into your project and get a fully functional embedded environment in minutes.

---

## Features

- Targets Cortex-M3, M4, and M33 (ARMv7-M / ARMv8-M.main)
- UART I/O for streaming test vectors and results
- Cycle-accurate benchmarking via SysTick
- `printf` over UART (tiny implementation, no host libc)
- Semihosting support for clean exit codes
- GDB debugging via QEMU's built-in stub
- Known Answer Test (KAT) friendly: feed vectors over UART, read results back

**Peripherals used:**

| Peripheral | Purpose                                      | Targets             |
|------------|----------------------------------------------|---------------------|
| UART0      | All serial I/O (`printf`, read/write API)    | all                 |
| SysTick    | Cycle counting for benchmarks                | all                 |
| FPU        | Hardware floating-point (enabled if present) | AN386, AN500, AN521 |
| GPIO0      | UART pin multiplexing (alt-function setup)   | AN385, AN386, AN500 |

---

## Supported Targets

| Preset | Board | CPU        | Architecture             |
|--------|-------|------------|--------------------------|
| an385  | AN385 | Cortex-M3  | ARMv7-M                  |
| an386  | AN386 | Cortex-M4  | ARMv7E-M + FPU           |
| an500  | AN500 | Cortex-M4  | ARMv7E-M + FPU (600 MHz) |
| an521  | AN521 | Cortex-M33 | ARMv8-M.main             |

Each target has 4 MiB instruction SRAM and 4 MiB data SRAM with a 200 KB stack.

---

## Requirements

- `arm-none-eabi-gcc`
- CMake >= 3.10 and Ninja
- QEMU with MPS2 support (`qemu-system-arm`)

---

## Building

Configure, build, and package for a target:

```bash
cmake --preset an385 && cmake --build --preset an385 && cpack --preset an385
cmake --preset an386 && cmake --build --preset an386 && cpack --preset an386
cmake --preset an500 && cmake --build --preset an500 && cpack --preset an500
cmake --preset an521 && cmake --build --preset an521 && cpack --preset an521
```

Additional build types: append `-debug`, `-minsizerel`, or `-minsizerel-armcompat` to any preset (e.g. `an385-debug`).

Packaged archives (`.tar.gz`) are placed in `out/package/<preset>/`.

---

## Running on QEMU

```bash
# Cortex-M3
qemu-system-arm -M mps2-an385 -nographic -semihosting -kernel out/an385/hello.bin

# Cortex-M4
qemu-system-arm -M mps2-an386 -nographic -semihosting -kernel out/an386/hello.bin

# Cortex-M33
qemu-system-arm -M mps2-an521 -nographic -semihosting -kernel out/an521/hello.bin
```

To redirect UART to a TCP port (useful for piping test vectors from a host script):

```bash
qemu-system-arm -M mps2-an385 -nographic -kernel out/an385/hello.bin \
    -serial tcp::1234,server,nowait
```

Connect with `nc localhost 1234` or `telnet localhost 1234`.

---

## Public API

Include `platform/platform.h`:

```c
// Initialize UART, SysTick, and FPU (if available).
// PLATFORM_CLOCK_USERSPACE fixes the clock to 24 MHz for reproducible benchmarks.
// PLATFORM_CLOCK_MAX runs at the target's full speed.
int platform_init(platform_op_mode_t mode);

// Blocking UART write/read over UART0.
int platform_io_write(const char *buf, int len);
int platform_io_read(char *buf, int len);

// Non-blocking readiness checks.
int platform_io_is_readable(void);
int platform_io_is_writable(void);

// Cycle-accurate benchmarking. Call platform_sync() before the first read
// to flush the CPU pipeline and get a clean baseline.
uint64_t platform_cpu_cyclecount(void);
void     platform_sync(void);

// Fill buf with len random bytes (TRNG stub).
int platform_get_random(void *buf, unsigned len);
```

`printf` / `fprintf` are available via `platform/printf.h` and output over UART0.

---

## Known Answer Testing (KAT)

KAT (Known Answer Test) is the standard method for validating cryptographic implementations: apply an algorithm to a fixed input and assert the output matches an expected (known) value. This runtime is well suited for KAT workflows because UART I/O lets you stream test vectors from a host script directly into the running firmware.

**Typical flow:**

1. The firmware reads a test vector from UART (`platform_io_read`)
2. Runs the cryptographic function under test
3. Writes the result back over UART (`platform_io_write`)
4. A host script compares the result against the expected value

**Example firmware (Cortex-M33):**

```c
#include <platform/platform.h>
#include <platform/printf.h>
#include <string.h>

// Assembly implementation under test
extern int crypto_hash(uint8_t *out, const uint8_t *in, size_t len);

int main(void) {
    platform_init(PLATFORM_CLOCK_USERSPACE);

    uint8_t msg[64], digest[32];
    int n = platform_io_read((char *)msg, sizeof(msg));

    platform_sync();
    uint64_t t0 = platform_cpu_cyclecount();
    crypto_hash(digest, msg, n);
    uint64_t cycles = platform_cpu_cyclecount() - t0;

    platform_io_write((char *)digest, sizeof(digest));
    printf("cycles: %llu\n", cycles);
    return 0;
}
```

**Host-side runner (Python example):**

```python
import socket, hashlib

EXPECTED = hashlib.sha256(b'\x00' * 64).digest()

with socket.create_connection(("localhost", 1234)) as s:
    s.sendall(b'\x00' * 64)
    result = s.recv(32)
    assert result == EXPECTED, f"KAT FAIL: got {result.hex()}"
    print("KAT PASS")
```

---

## Integrating into Your Project

### Option A: CMake FetchContent (recommended)

Fetches and builds the runtime as part of your own CMake project. No separate build step needed — the runtime is compiled with the same toolchain already active in your project.

**`CMakeLists.txt`:**

```cmake
cmake_minimum_required(VERSION 3.10)
project(my_crypto_test C ASM)

include(FetchContent)

FetchContent_Declare(
    mps2rtm
    GIT_REPOSITORY https://github.com/kriskwiatkowski/runtime_mps2.git
    GIT_TAG        v0.0.9
)
FetchContent_MakeAvailable(mps2rtm)

add_executable(my_test main.c my_crypto.S)

target_link_libraries(my_test PRIVATE mps2rtm)

target_link_options(my_test PRIVATE
    -T${mps2rtm_BINARY_DIR}/mps2.ld
    -nostartfiles
    -Wl,--whole-archive $<TARGET_FILE:mps2rtm> -Wl,--no-whole-archive)
```

`mps2rtm_BINARY_DIR` is set automatically by `FetchContent_MakeAvailable` and points to the build directory containing the generated `mps2.ld` linker script.

**Configure and build:**

```bash
cmake -DCMAKE_TOOLCHAIN_FILE=<path-to-mps2rtm>/toolchains/gcc-armv7_m-unknown-none-eabi.toolchain \
      -DFLAVOUR=AN385 -G Ninja -B build
cmake --build build
qemu-system-arm -M mps2-an385 -nographic -semihosting -kernel build/my_test
```

### Option B: Prebuilt archive

Download a release archive from the [Releases page](https://github.com/kriskwiatkowski/runtime_mps2/releases):

```bash
tar -xf mps2rtm_AN385_0.0.9_release.tar.gz -C deps/mps2rtm
```

The archive contains:

- `lib/libmps2rtm.a` — static runtime library
- `lib/mps2.ld` — linker script for the target
- `include/platform/platform.h`, `printf.h` — public headers

```cmake
set(MPS2RTM_DIR ${CMAKE_SOURCE_DIR}/deps/mps2rtm)

add_executable(my_test main.c my_crypto.S)

target_include_directories(my_test PRIVATE ${MPS2RTM_DIR}/include)

target_link_options(my_test PRIVATE
    -T${MPS2RTM_DIR}/lib/mps2.ld
    -nostartfiles
    -Wl,--whole-archive ${MPS2RTM_DIR}/lib/libmps2rtm.a -Wl,--no-whole-archive)
```

### Note on `--whole-archive`

The runtime uses weak symbols that applications can override. Without `--whole-archive`, the linker skips object files that appear to have no unresolved dependencies, silently dropping the strong symbol definitions. Always wrap `libmps2rtm.a` with `--whole-archive` / `--no-whole-archive`.

---

## Debugging with GDB

Build with a `-debug` preset to include debug symbols, then start QEMU halted:

```bash
qemu-system-arm -M mps2-an385 -nographic -semihosting \
    -kernel out/an385-debug/hello.bin -s -S
```

`-s` opens the GDB stub on port 1234. `-S` pauses execution until GDB connects.

Attach in a second terminal:

```bash
arm-none-eabi-gdb out/build/an385-debug/hello
(gdb) target remote :1234
(gdb) load
(gdb) break main
(gdb) continue
```

From here you can step through assembly instruction by instruction (`stepi`), inspect registers (`info registers`), and set watchpoints on memory addresses.

---

## Project Structure

```text
src/          Runtime library sources (startup, UART, init, printf, handlers)
inc/platform/ Public headers
app/          Example applications (hello world, I/O echo)
toolchains/   CMake toolchain files for ARMv7-M, ARMv7E-M, ARMv8-M
cmake/        Post-build and install rules
```

---

## License

GNU General Public License v2.
