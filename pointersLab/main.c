#include <stdio.h>

#include "student.h"
#include "course.h"

int main(void)
{
	// Declare a roster array of students, which will use MAX_STUDENTS
	Student_t *master_roster[MAX_STUDENTS];
	Student_t students[MAX_STUDENTS];
	
	// Initialize at least six entries with realistic names and GPAs

	for (int i = 0; i < MAX_STUDENTS; i++) {
		master_roster[i] = NULL;
	}

	
	master_roster[0] = &students[0];
	addStudent(master_roster[0], "Alice","Anderson", 3.80);
	
	master_roster[1] = &students[1];
	addStudent(master_roster[1], "Bob","Baker", 3.80);

	master_roster[2] = &students[2];
	addStudent(master_roster[2], "Carol","Clark", 3.80);

	master_roster[3] = &students[3];
	addStudent(master_roster[3], "David","Doe", 3.80);

	master_roster[4] = &students[4];
	addStudent(master_roster[4], "Eve","Evans", 3.80);

	master_roster[5] = &students[5];
	addStudent(master_roster[5], "Frank","Foster", 3.80);
	
		
	// Print the entire master roster

	printf("=== Master Roster ===\n");
	for (int i = 0; i < MAX_STUDENTS; i++) {
		if (master_roster[i])
			printStudent(master_roster[i]);
	}



	
	// Initialize a Course myClass

	Course_t myClass;
	addCourse(&myClass);


	
	// Add a subset of the roster to the course

	addStudentToCourse(&myClass, &students[0]);
	
	addStudentToCourse(&myClass, &students[1]);

	addStudentToCourse(&myClass, &students[2]);

	
	// Print the Current Roster

	printCourse(&myClass);
	
	
	//Filling the course completely


	//first, adding the previously defined students
	for (int i = 3; i < 6; i++) {
		addStudentToCourse(&myClass, &students[i]);
	}


	//creating test students and adding them to the class
	for (int i = 6; i < MAX_STUDENTS; i++) {
		master_roster[i] = &students[i];
		char firstName[31];
		char lastName[31]; 
		sprintf(firstName, "first%d", i);
		sprintf(lastName, "last%d", i);
		float gpa = 4.00;
		addStudent(master_roster[i], firstName, lastName, gpa);
		addStudentToCourse(&myClass, &students[i]);
	}

	// Attempt to over-fill the course to demonstrate the error case

	printf("\nFilling the roster\n");

	Student_t last_student = {"Zesty", "Zillion", 2.00};

	addStudentToCourse(&myClass, &last_student);

		
	
	// Print the course roster, showing only valid students

	printCourse(&myClass);
}
