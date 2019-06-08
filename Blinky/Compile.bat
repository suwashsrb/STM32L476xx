arm-none-eabi-gcc -g -static -mthumb -mcpu=cortex-m4 main.c init.c LED.c Button.c -T linker_script.ld -o main.elf -nostartfiles
arm-none-eabi-objcopy -O binary main.elf main.bin
pause