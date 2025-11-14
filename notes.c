#include <stdio.h>

int main(void) {

/*The C toolchain is a set of development tools used in association with source code

The toolchain is used for compilation, preparing libraries, reading a binary file, and debugging

Normal parts of a toolchain:

COMPILER: generate the object files from source code
LINKER: link the object files together into a binary file
DEBUGGER: debug the binary file while it runs

We will use a different debugger from the default because the maker's own is bad

Two micro usb ports on the board: one for data and one solely for power

-----------
The GNU toolchain for ARM
-----------

Contains packages
Supports C or C++; we will use C
Supports CPUs utilizing A, R, and M profiles

GNU toolchain supports all 3 OSs

The output of the compilation is the RELOCATABLE OBJECT FILE

The object file utilizes the ELF FILE FORMAT:
1) a binary code
2) a symbol table

The SYMBOL TABLE:
1) names static and global variables in the file
2) names static and global variables used in the source file
3) functions defined by the source file
4) functions used within the source file

LINKING PROCESS: takes all the object files and symbol files and combines them into a single executable

The symbol table is not necessary for running the executable, but it is useful when running the debugger

The LINKER SCRIPT EXAMPLE:*/
//----------------------------------------------------------

/* Define the end of RAM and limit stack memory */
/* _estack specifies address where RAM segment ends */

//_estack = 0x00000000;

/* xxx KB SRAM on the STM32Fxxx, xxx, KB*/
/* (RAM starts at address 0x0000 0000 */
/* r = readable */
/* x = executable */
/* w = writable */

//MEMORY
//{
	/* Flash Location and Length */
//	FLASH ( --- ) : ORIGIN = 0x00000000, LENGTH = xxx;
	/*RAM Location and Length */
//	RAM ( --- ) : ORIGIN = 0x00000000, LENGTH = xxx;
//}


//----------------------------------------------------------

/* LINKER SCRIPT example for an STM32L432KC with 256KB flash and 64KB RAM.

Use the chip's memory map to find where you can put the RAM


You must specify where the Data Segment (initialized variables), the BSS Segment (variables not initialized), the HEAP, and the STACK
*/


_estack = 0x20010000;

/* r = readable */
/* x = executable */
/* w = writable */

//MEMORY
//{
	/* Flash Location and Length */
//	FLASH ( rx ) : ORIGIN = 0x08000000, LENGTH = 256K;
	/*RAM Location and Length */
//	RAM ( rxw ) : ORIGIN = 0x20000000, LENGTH = 64K;
//}

/*

See the assembly example in 

------------------
core.S
------------------
