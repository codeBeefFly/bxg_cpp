#include "teacher.h"

Teacher::Teacher(std::string name, int age, std::string subject)
	: name{ name }
	, age{ age }
	, subject{ subject }{

	std::cout << "..log::Teacher 的构造函数...\n";

}

Teacher::~Teacher() {
	
	std::cout << "..log::Teacher 的析构函数...\n";

}