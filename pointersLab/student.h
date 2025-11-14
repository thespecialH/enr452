#ifndef STUDENT_H
#define STUDENT_H

#include <stddef.h>

/* -------------------------------------------------------------
 *  Student – holds basic personal data and a GPA.
 * ------------------------------------------------------------- */
typedef struct Student 
{
    char first[31];             /* room for up to 30 chars + terminating '\0' */
    char last[31];              /* room for up to 30 chars + terminating '\0' */
    float gpa;
} Student_t;

void addStudent( Student_t *student,
                  const char *first,
                  const char *last,
                  float gpa );

void printStudent( const Student_t *student );

#endif /* STUDENT_H */
