#include "Student.h"



// �޲ι��캯��
Student::Student() 
	: Student("unknown", "000", {}) {
	std::cout << "..log::�޲ι��캯��...\n";
}

// ȫ�ι��캯��
Student::Student(std::string name, std::string id, std::vector<int> score_vector) 
	: name{ new std::string{name} }, 
	id{ id }, 
	score_vector{ score_vector } {
	std::cout << "..log::ȫ�ι��캯��...\n";
}

// ǳ�������캯������ֵ
//Student::Student(const Student& stu);

// ������캯������ֵ
Student::Student(const Student& stu) {
	std::cout << "..log::������캯��...\n";
	this->name = new std::string{ *stu.name };
}

// �ƶ����캯������ֵ
Student::Student(Student&& stu) {
	std::cout << "..log::�ƶ����캯��...\n";
	this->name = stu.name;
	stu.name = nullptr;
}

// ��������
Student::~Student() {
	std::cout << "..log::��������...\n";
	delete this->name;
	this->name = nullptr;
}


