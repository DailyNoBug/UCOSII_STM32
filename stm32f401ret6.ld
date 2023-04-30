/* stm32f401ret6.ld - linker script for STM32F401RE-T6 */

ENTRY(Reset_Handler)

/* Specify the memory regions */
MEMORY
{
  FLASH (rx)      : ORIGIN = 0x08000000, LENGTH = 512K
  SRAM  (rwx)     : ORIGIN = 0x20000000, LENGTH = 96K
}

/* Define the sections */
SECTIONS
{
  /* The program code is located in the FLASH memory */
  .text :
  {
    *(.isr_vector)
    *(.text)
    *(.rodata)
    *(.rodata*)
    . = ALIGN(4);
  } > FLASH

  /* The data section is located in the SRAM memory */
  .data :
  {
    *(.data)
    . = ALIGN(4);
  } > SRAM AT > FLASH

  /* The BSS section is also located in the SRAM memory */
  .bss :
  {
    *(.bss)
    *(.bss*)
    . = ALIGN(4);
  } > SRAM

  /* Define the stack and heap sections */
  stack_top = ORIGIN(SRAM) + LENGTH(SRAM);
  .stack :
  {
    . = ALIGN(4);
    _stack_top = .;
  } > SRAM

  .heap :
  {
    . = ALIGN(4);
    _heap_bottom = .;
    . = . + 16K; /* Set the heap size to 16K */
    . = ALIGN(4);
    _heap_top = .;
  } > SRAM
}