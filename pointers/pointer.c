#include <stdio.h>

int main(void) {

	int a = 10;
	int *ptr;

	ptr = &a;

	printf("Address of a: %p\n", &a);
	printf("Address of a: %p\n", ptr);
	printf("Address of ptr: %p\n", &ptr);

}
