#include "Teacher.h"


Teacher::Teacher() : Teacher("unknown_name", 0, "unknown_subject") {

}

Teacher::Teacher(std::string name, int age, std::string subject)
	: name{ name }
	, age{ age }
	, subject{ subject } {
	
	std::cout << "..log::Teacher �вι���...\n";
}

Teacher::~Teacher() {
	std::cout << "..log::Teacher ��������...\n";
}


std::istream& operator>>(std::istream& in, Teacher& teacher) {
	in >> teacher.name >> teacher.age >> teacher.subject;
	return in;
}


std::ostream& operator<<(std::ostream& out, Teacher& teacher) {
	out << teacher.name << ", " << teacher.age << ", " << teacher.subject << "\n";
	return out;
}