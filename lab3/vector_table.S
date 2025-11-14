.syntax unified 
.cpu cortex-m7
.fpu softvfp 
.thumb 

// Global variables
.global vtable 
.global default_interrupt_handler 

// The vector table.
.type vtable, %object 
.section .vector_table,"a",%progbits 
vtable: 
.word _estack                 
.word reset_handler
.word NMI_handler
.word hard_fault_handler
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word SysTick_handler


// Location to Boot from RAM startup
#define boot_ram_base 0xF108F85F
.word boot_ram_base

// Set up weak aliases for each exception handler
.weak NMI_handler
.thumb_set NMI_handler,default_interrupt_handler

.weak hard_fault_handler
.thumb_set hard_fault_handler,default_interrupt_handler

.weak SysTick_handler
.thumb_set SysTick_handler,default_interrupt_handler

.size vtable, .-vtable

// Default interrupt handler, for interrupts not defined
.section .text.default_interrupt_handler,"ax",%progbits

default_interrupt_handler:
   default_interrupt_loop:
      B default_interrupt_loop

.size default_interrupt_handler, .-default_interrupt_handler

