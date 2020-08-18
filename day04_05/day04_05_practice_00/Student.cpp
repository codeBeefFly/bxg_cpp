#include "Student.h"


// 类中的成员函数在外部定义的写法
void Student::read() {
	std::cout << "..[" << age << "]岁的[" << name << "]在读书...\n";
}


void Student::run() {
	std::cout << "..[" << age << "]岁的[" << name << "]在跑步...\n";
}