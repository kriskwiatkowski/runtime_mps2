# Runtime for stm32f4 platform

Creates runtime environment that allows running apps on MPS AN386 via QEMU. One needs to build the solution, link resulting static library with the application and push to the board. Solution contains implementation of `printf` that sends data over UART to the terminal.

## Building

```
cmake --preset an386
cmake --build --preset an386
```

Libraries will be compiled and placed in the ``build/pack`` directory.


## Test program

To run test program:
```
qemu-system-arm -M mps2-an386 -nographic -semihosting -kernel out/an386/hello.bin
```