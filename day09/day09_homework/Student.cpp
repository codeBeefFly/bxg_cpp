#include "Student.h"


Student::Student() {
	std::cout << "..log::Student �޲ι���...\n";
}

Student::Student(std::string name, int age, Gender gender) {
	std::cout << "..log::Student �вι���...\n";
}

Student::~Student() {
	std::cout << "log::Student ����...\n";
}

void setTeacher(std::shared_ptr<Teacher> sp_t) {
	this.sp_teacher = sp_t;
}