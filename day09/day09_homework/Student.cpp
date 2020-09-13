#include "Student.h"


Student::Student() {
	std::cout << "..log::Student 无参构造...\n";
}

Student::Student(std::string name, int age, Gender gender) {
	std::cout << "..log::Student 有参构造...\n";
}

Student::~Student() {
	std::cout << "log::Student 析构...\n";
}

void setTeacher(std::shared_ptr<Teacher> sp_t) {
	this.sp_teacher = sp_t;
}