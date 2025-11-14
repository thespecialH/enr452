/*For CORETEX-M4 */
/* Define the end of RAM and limit the stack memory */
/* ??? KB SRAM of the STM32H755 */
/** RAM starts at address 0x30000000 */
/* Memory Attributes */
/* r = readable */
/* x = executable */
/* w = writable */

/* _estack specifies the address where the RAM segments ends */
/* Task #1: Define the end-of-stack */
_estack = 0x30047FFF;

MEMORY
{
	/* Flash Location and Length */
	/* Task #2: Define the Start and Length of Flash Memory */
	FLASH(rx) : ORIGIN = 0x08100000, LENGTH = 1024K

	/* RAM Location and Length */
	/* Task #3: Define the Start and Length of RAM */
	RAM(rwx) : ORIGIN = 0x30000000, LENGTH = 288K
}

