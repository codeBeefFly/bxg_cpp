#include "Teacher.h"


// Teacher ���캯��
Teacher::Teacher() : Teacher("unknown", "unknown_subject") {
	std::cout << "..log::Teacher �޲ι���...\n";
}

Teacher::Teacher(std::string name, std::string subject)
	: Human{ name }	// ʹ�ø����вι����ʼ�� name
	, subject{ subject }{
	std::cout << "..log::Teacher �вι���...\n";
}

Teacher::~Teacher() {
	std::cout << "..log::Teacher ��������...\n";
}

// ����+��д����
void Teacher::work() {
	std::cout << "\n***********************************\n";
	// ��ӡ��Ϣ
	// ��ʦ����Ϣ+ѧ������Ϣ

	std::cout << "..��ʦ����Ϣ...\n"
		<< "...����::\t" << this->name
		<< "...ѧ��::\t" << this->subject
		<< "\n";

	std::cout << "..ѧ������Ϣ...\n"
		<< "...����::\t" << wp_student.lock()->name	// ��ָ����ȡ�ù���ָ��
		<< "...ѧ��::\t" << wp_student.lock()->id
		<< "\n";
}

// ƥ��ѧ��
void Teacher::setStudent(std::shared_ptr<Student> sp_student) {
	this->wp_student = sp_student;
}