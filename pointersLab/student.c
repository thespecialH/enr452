#include <stdio.h>
#include <string.h>

#include "student.h"

void addStudent( Student_t *student,
                 const char *first,
                 const char *last,
                 float gpa)
{
	strncpy(student->first, first, 30);
	strncpy(student->last, last, 30);
	student->gpa = gpa;
}


void printStudent( const Student_t *student )
{
	printf("%s\t%s\t%0.2f\n", student->last, student->first, student->gpa);
}

