.syntax unified
.cpu cortex-m7
.fpu softvfp
.thumb

//Global values.
.global vtable //Vector table
.global reset_handler //that's the reset_handler function

//This is the vector table
//Most entries are omitted for simplicity
.type vtable, %object
vtable:
	.word _estack
	.word reset_handler
.size vtable, .-vtable


.type reset_handler, %function //called on Reset
reset_handler:
	// set the stack pointer to the end of the stack.
	//the '_estack' value is defined in our linker script.
	LDR r0, = _estack
	MOV sp, r0

	//set some dummy values, when we see the values we'll know it's working
	LDR r7, =0xABADFEED // <-- come up with a new one
	MOVS r0, #0

	main_loop:
	// Add 1 to register 'r0'.
	ADDS r0, r0, #1

	//loop back
	B main_loop

.size reset_handler, .-reset_handler
