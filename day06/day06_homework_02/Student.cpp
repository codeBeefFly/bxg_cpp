#include "Student.h"

std::string Student::university = "JNTUH";

Student::Student() : Student("unknown", "00x", {}) {
	std::cout << "..log::�޲ι���...\n";
}

Student::Student(std::string name, std::string id, std::vector<int> score_vector)
	: name{ new std::string{name} }
	, id{ id }
	, score_vector{ score_vector }{
	std::cout << "..log::�вι���...\n";
}

Student::~Student() {
	std::cout << "..log::����...\n";
	delete name;
	name = nullptr;
}
