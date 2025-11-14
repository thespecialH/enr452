#include <stdio.h>

int main(void) {

	int a = 42;

	int *a_ptr = '\0';

	printf("a_ptr: %p\n",a_ptr);

	a_ptr = &a;

	printf("a_ptr: %p\n", a_ptr);

}
