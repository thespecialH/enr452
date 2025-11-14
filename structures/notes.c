#include <stdio.h>

int main(void) {


	//this is a structure definition
	struct Weight {
		int pounds;
		int ounces;
		char style[21];
	};

	//use periods to reference individual parts
	struct Weight hamburger;
	hamburger.pounds = 1;
	hamburger.ounces = 4;

	//you can also use this version
	struct Weight hamburger = {1,4,"bison"};
	//here's an example of how to call utilizing the period
	printf("%s", hamburger.style);
}

	//You can define structures within structures

int main(void){

	struct Student {
		char name[21];
		int id;
		float gpa;
	};

	struct Class {
	//I think this means there are an array of 20 Student structures, each with a name, id, and gpa
		struct Student student[20];
		int count;
	}


	//You can use a structure as a parameter

	void print_student(struct Student) {
		printf("student:%s\nID:%d\nGPA:%f\n", student.name,student.id,student.gpa);
	}

	//You can use it as a return value, (think of "struct Student" as replacing "int" or the like)

	//don't do this? (use pointers instead)
	struct Student getStudent() {
		struct Student st;
		strcpy(st.name, "Daneel Olivaw");
		st.id=1234;
		st.gpa=3.78;
		return st;
	}

	//We will now make an instance of the Class structure

	struct Class enr452 = {
		{"Mark",1234,2.89},
		{"Pam",6789,4.12},
		//and so on for all 20 students
		{"Guy",2345,0.5};
	}



}


