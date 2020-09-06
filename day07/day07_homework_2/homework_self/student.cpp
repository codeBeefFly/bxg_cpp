#include "student.h"


Student::Student(std::string name, std::string id, Teacher* teacher)
	: name{ name }
	, id{ id }
	, teacher{ new Teacher }{
	
	std::cout << "..log::Student �вι���...\n";

}

Student::~Student() {
	
	std::cout << "..log::Student ��������...\n";
	
	delete teacher;

}