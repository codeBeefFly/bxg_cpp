#include "student.h"


Student::Student(std::string name, std::string id, Teacher* teacher)
	: name{ name }
	, id{ id }
	, teacher{ new Teacher }{
	
	std::cout << "..log::Student 有参构造...\n";

}

Student::~Student() {
	
	std::cout << "..log::Student 析构函数...\n";
	
	delete teacher;

}