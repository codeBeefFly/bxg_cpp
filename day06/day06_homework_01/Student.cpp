#include "Student.h"



// 无参构造函数
Student::Student() 
	: Student("unknown", "000", {}) {
	std::cout << "..log::无参构造函数...\n";
}

// 全参构造函数
Student::Student(std::string name, std::string id, std::vector<int> score_vector) 
	: name{ new std::string{name} }, 
	id{ id }, 
	score_vector{ score_vector } {
	std::cout << "..log::全参构造函数...\n";
}

// 浅拷贝构造函数，左值
//Student::Student(const Student& stu);

// 深拷贝构造函数，左值
Student::Student(const Student& stu) {
	std::cout << "..log::深拷贝构造函数...\n";
	this->name = new std::string{ *stu.name };
}

// 移动构造函数，右值
Student::Student(Student&& stu) {
	std::cout << "..log::移动构造函数...\n";
	this->name = stu.name;
	stu.name = nullptr;
}

// 析构函数
Student::~Student() {
	std::cout << "..log::析构函数...\n";
	delete this->name;
	this->name = nullptr;
}


