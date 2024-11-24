# Runtime for stm32f4 platform

Creates runtime environment that allows running apps on MPS AN386 (ARM Cortex-M4) and AN385 (ARM Cortex-M3) via QEMU. One needs to build the solution, link resulting static library with the application and push to the board. Solution contains implementation of `printf` that sends data over UART to the terminal.

## Building

There are 2 configurations : 'an385' (Cortex-M3) and 'an386' (Cortex-M4). Here below I'll build for 'an386'.

```
cmake --preset an386
cmake --build --preset an386
```

Libraries will be compiled and placed in the ``build/pack`` directory.


## Test program

To run test program on Cortex M3:
```
qemu-system-arm -M mps2-an385 -nographic -semihosting -kernel out/an385/hello.bin
```

To run test program on Cortex M4:
```
qemu-system-arm -M mps2-an386 -nographic -semihosting -kernel out/an386/hello.bin
```