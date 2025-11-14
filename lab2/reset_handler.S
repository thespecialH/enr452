.syntax unified
.cpu cortex-m7
.fpu softvfp
.thumb

// Global variables
.global reset_handler

/* The Reset handler. Called on reset. */ 
.type reset_handler, %function 
reset_handler: 

//Set the stack pointer to the end of the stack
LDR r0, =_estack
MOV sp, r0

//Copy data from flash to RAM data section
MOVS r0, #0

//load the start/end addresses of the data section
LDR r1, =_sdata
LDR r2, =_edata
LDR r3, =_sidata
B copy_sidata_loop

copy_sidata:

//offset the data init section by copy progress
LDR r4, [r3, r0]

//copy the current word into data then increment
STR r4, [r1, r0]
ADDS r0, r0, #4
copy_sidata_loop:

//copy more data as needed
ADDS r4, r0, r1
CMP r4, r2
BCC copy_sidata

//done copying, get ready to fill the BSS section with 0
MOVS r0, #0
LDR r1, =_sbss
LDR r2, =_ebss
B reset_bss_loop

reset_bss:
STR r0, [r1]
ADDS r1, r1, #4


reset_bss_loop: 
CMP r1, r2
BCC reset_bss



// Branch to the 'main' method. 
B main

.size reset_handler, .-reset_handler
