#include <stdio.h>

int main(void) {

	int a = 12;
	int b = 4;
	int *ptr1 = &a;
	int *ptr2 = &b;
	int x = *ptr1 * *ptr2 - 6;

	int y = 4* - *ptr2 / *ptr1 + 10;

	printf("address a: %p\taddress b: %p\n", ptr1, ptr2);
	printf("value x: %d\tvalue y: %d\n", x, y);

}
