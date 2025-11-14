.syntax unified
.cpu cortex-m4
.fpu softvfp
.thumb

//Global values.
.global vector_table //Vector table
.global reset_handler //that's the reset_handler function

//This is the vector table
//Most entries are omitted for simplicity
.type vtable, %object
vector_table:
	.word _estack
	.word reset_handler
.size vector_table, .-vector_table


.type reset_handler, %function //called on Reset
reset_handler:
	// set the stack pointer to the end of the stack.
	//the '_estack' value is defined in our linker script.
	LDR r10, = _estack
	MOV sp, r10

	//set some dummy values, when we see the values we'll know it's working
	LDR r7, =0xABBADEAF // <-- come up with a new one
	MOVS r10, #0

	main_loop:
	// Add 1 to register 'r10'.
	ADDS r10, r10, #1

	//loop back
	B main_loop

.size reset_handler, .-reset_handler
