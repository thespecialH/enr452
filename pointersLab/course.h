#ifndef COURSE_H
#define COURSE_H

#include "student.h"

#define MAX_STUDENTS 20

/* -------------------------------------------------------------
 *  Course – a collection of pointers to Student objects.
 * ------------------------------------------------------------- */
typedef struct Course
{
    Student_t *students[MAX_STUDENTS];      /* pointers to existing Student structs */
    int count;                              /* how many students are currently stored */
} Course_t;

/* Initialise an empty Course */
void addCourse( Course_t *c );

/* Add a Student pointer to the Course.
 * Returns 0 on success, -1 if the Course already holds MAX_STUDENTS.
 */
int addStudentToCourse( Course_t *c, Student_t *s );

/* Print all students enrolled in the Course */
void printCourse( const Course_t *c );

#endif /* COURSE_H */
