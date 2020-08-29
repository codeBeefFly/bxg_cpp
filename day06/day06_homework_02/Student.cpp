#include "Student.h"

std::string Student::university = "JNTUH";

Student::Student() : Student("unknown", "00x", {}) {
	std::cout << "..log::无参构造...\n";
}

Student::Student(std::string name, std::string id, std::vector<int> score_vector)
	: name{ new std::string{name} }
	, id{ id }
	, score_vector{ score_vector }{
	std::cout << "..log::有参构造...\n";
}

Student::~Student() {
	std::cout << "..log::析构...\n";
	delete name;
	name = nullptr;
}
