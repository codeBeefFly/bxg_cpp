#include "teacher.h"

Teacher::Teacher(std::string name, int age, std::string subject)
	: name{ name }
	, age{ age }
	, subject{ subject }{

	std::cout << "..log::Teacher �Ĺ��캯��...\n";

}

Teacher::~Teacher() {
	
	std::cout << "..log::Teacher ����������...\n";

}