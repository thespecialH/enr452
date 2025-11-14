#include <stdio.h>
#include <stdlib.h>
int main(void){

/*
-------------------
NOTES ON POINTERS 9/22/2025

cross-platform development: everything must be manual. What addresses is the memory at?

The LINKER FILE says "<this much> memory is at <this location>" (an address)

This way, the LINKER knows where to put the stuff: text/code segment, initialized data segment, uninitialized data segment, into the correct place.

The STACK is used to store local variables and pass arguments. The stack is created when control enters a block of code.

The HEAP allocates memory using MALLOC or CALLOC (dynamic memory management functions). It is shared by all libraries & dynamically loaded modules.

Use FREE to free up the memory from a pointer.

A diagram of the stack & heap:

______________________________
|                            |
|    Command Line Arguments  | <--
|----------------------------|
|           Stack            |
|----------------------------|
|             |              | <--
|		      |              |
|		      |              |       Dynamic memory layout
|		      \/             |
|----------------------------| <--
|		      /\             |
|		      |              |
|		      |              |
|		      |              | <--
|----------------------------|
|            Heap            |
|----------------------------|-----------------------------
| Uninitialized data segment | <--
|----------------------------|    
|  Initialized data segment  | <--   Static memory layout
|----------------------------|
|     Text/Code segment      | <--
|____________________________|


VARIABLES: they contain the name, value, & address of memory location:
*/

int count;

/*The variable "count" is now in the stack. When you reference "count", you reference the memory location in the stack.

A POINTER is a variable that contains an address <-- the address of another variable located elsewhere:
*/

int *count_ptr;

/*You use the ASTERISK to declare a pointer. "count_ptr" is now win the stack, pointing to the heap.
Example:
*/

int digit = 50;
int *digit_ptr;

digit_ptr = &digit;

/*Now "digit_ptr" stores the address of "digit".

THINK --> & = "address of"

However you define it, the pointer variable will always be 4 BYTES long, no matter what it's pointing to. This way it is guaranteed to hold whole memory address.

THINK --> * = "the stuff at"


------------------------------------
NOTES ON ENDIANNESS:

BIG ENDIAN vs LITTLE ENDIAN

Big Endian stores the most significant byte first

Little Endian stores the least significant byte first

For INSTANCE:

32-bit address in Big Endian: x0D x0C x0B x0A
sent to Little Endian: x0A x0B x0C x0D

Big endian is the most common


-----------------------------------
NOTES ON FUNCTIONS RELEVANT TO POINTERS WITHIN stdlib.h

malloc() - allocates a single block of memory
calloc() - allocates multiple blocks of memory
realloc() - reallocates memory occupied <------DANGEROUS! Volkman has never used
free() - frees dynamically allocated memory


here is an EXAMPLE:*/

int num = 4;

int *num_ptr;

num_ptr = (int *)malloc(num *sizeof(int));

}
