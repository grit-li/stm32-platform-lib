ENTRY(reset_handler)

MEMORY
{
    RAM (xrw)      : ORIGIN = 0x20000000, LENGTH = 96K
    RAM2 (xrw)      : ORIGIN = 0x10000000, LENGTH = 32K
    FLASH (rx)      : ORIGIN = 0x8000000, LENGTH = 512K
}

SECTIONS
{
    .isr_vector :
    {
        . = ALIGN(8);
        KEEP(*(.isr_vector))
        . = ALIGN(8);
    } >FLASH

    .text :
    {
        . = ALIGN(8);
        *(.text)
        *(.text*)
        . = ALIGN(8);
    } >FLASH

    .rodata :
    {
        . = ALIGN(8);
        *(.rodata)
        *(.rodata*)
        . = ALIGN(8);
    } >FLASH

    _sidata = LOADADDR(.data);

    .data : 
    {
        . = ALIGN(8);
        _sdata = .;
        *(.data)
        *(.data*)

        . = ALIGN(8);
        _edata = .;
    } >RAM AT> FLASH

    . = ALIGN(4);
    .bss :
    {
        _sbss = .;
        *(.bss)
        *(.bss*)
        . = ALIGN(4);
        _ebss = .;
    } >RAM
}

PROVIDE(_stack = ORIGIN(RAM) + LENGTH(RAM));
