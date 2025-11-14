#include <stdio.h>
/* These are notes

---------------------
       UNIONS
---------------------

-> Similar to structures
-> Allows storing different data types in the same memory location
-> It can have many members
---> Only one member can contain a value at a time

Example: */

typedef struct Employee
{
	char name[30];
	double salary;
	int workNo;
	char classification;
} employee_t;

/* Here is an example of a program using the above structure:*/

int structFunction()
{
	employee_t employee = {"Hayden Fox",23500,12345,'C'};

	printf("Sizeof employee_t: %d\n", sizeof(employee));
	printf("name: %s\n", employee.name);

}

/*and here is an example of the thing with a union*/

typedef union Employee_union
{
	char name[30];
	double salary;
	int workNo;
	char classification;
} employee_union_t;

int unionFunction()
{
	employee_union_t employee = {"Hayden Fox",23500,12345,'C'};

	printf("Sizeof employee_t: %d\n", sizeof(employee));
	printf("name: %s\n", employee.name);
}

int main() {
	printf("Struct:\n");
	structFunction();
	printf("Union:\n");
	unionFunction();
}
