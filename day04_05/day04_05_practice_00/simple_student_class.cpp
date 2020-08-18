#include <iostream>
#include "Student.h"

int main(){
	std::cout << "..in simple_student_class...\n";

	Student student;

	student.name = "jacob";
	student.age = 18;

	student.read();
	student.run();

	return 0;
}