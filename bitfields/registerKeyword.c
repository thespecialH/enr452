#include <stdio.h>
/*These are notes

----------------------
 The Register Keyword
----------------------

It tells the compiler that a variable should be kept in a
register on the MCU, instead of keeping it in memory.
*/

int main() {
register int example_variable;
}

/*remember, there are not very many registers on the MCU, so
use this limitedly and sparingly, only when you need something
really fast. You lose access to the specified register during
the scope of whatever it's doing.*/
