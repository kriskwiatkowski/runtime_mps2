# Runtime for ARM MPS2 platform

Creates runtime environment that allows running apps on MPS AN386 (ARM Cortex-M4) and AN385 (ARM Cortex-M3) via QEMU. One needs to build the solution, link resulting static library with the application and push to the board. Solution contains implementation of `printf` that sends data over UART to the terminal.

## Building

There are 2 configurations : 'an385' (Cortex-M3) and 'an386' (Cortex-M4). Here below I'll build for 'an386'.

```
cmake --preset an385
cmake --build --preset an385
cpack --preset an385

cmake --preset an386
cmake --build --preset an386
cpack --preset an386
```

Libraries will be compiled and placed in the ``build/pack`` directory.

## Linking with applications

For some of the symbols, the runtime defines weak and strong symbols. It is hence important to use ``--whole-archive`` linker flag when linking the .a file.

Normally, the linker only extracts object files from the library if they provide undefined symbols required by the application. While linking, if the application gets a weak symbol it won't try to resolve strong one. Weak symbols do not create unresolved references, so if any symbol is already defined (even as a weak symbol), the linker does not search ``.a`` for another definition. It is called lazy extraction.

Use of the ``--whole-archive`` linker flag when linking the ``.a`` forces the linker to extract all the symbols, preventing the lazy extraction behavior.

## Test program

To run test program on Cortex M3:
```
qemu-system-arm -M mps2-an385 -nographic -semihosting -kernel out/an385/hello.bin
```

To run test program on Cortex M4:
```
qemu-system-arm -M mps2-an386 -nographic -semihosting -kernel out/an386/hello.bin
```