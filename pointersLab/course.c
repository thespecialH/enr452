#include <stdio.h>

#include "course.h"

//this creates a course and initializes the counter
void addCourse( Course_t *c )
{
	c->count = 0;
}

//this is how students are added to the course, ensuring the course is not filled beyond capacity (MAX_STUDENTS)
int addStudentToCourse( Course_t *c, Student_t *s )
{
	if (c->count < MAX_STUDENTS) {
		c->students[c->count] = s;
		c->count++;
		return 0;
	}
	else {
		printf("\nENR452 Course is full -- cannot add student %d\n\n", c->count+1);
		return -1;
	}
}

//print out the whole course roster
void printCourse( const Course_t *c )
{
	printf(" === ENR 452 Roster ===\n");
	printf("Course roster (%d students):\n", c->count);
	for (int i = 0; i < c->count; i++) {
		printf("%d) %s\t%s\t%0.2f\n", i+1, c->students[i]->last, c->students[i]->first, c->students[i]->gpa);
	}

}

