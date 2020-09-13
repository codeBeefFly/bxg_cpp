#include "Student.h"



// Student ����+��������
//Student::Student() : Student("unknown", "100xx", Gender::MALE) {
//	std::cout << "..log::Student �޲ι���...\n";
//}

Student::Student(){
	std::cout << "..log::Student �޲ι���...\n";
}

//Student::Student(std::string name, std::string id, Gender gender)
//	: Human{ name }		// ���ø�����вι���
//	, id{ id }
//	, gender{ gender }{
//	std::cout << "..log::Student �вι���...\n";
//}

Student::Student(std::string name, std::string id, Gender gender)
	: id{ id } {
	std::cout << "..log::Student �вι���...\n";
	this->name = name;
	this->gender = gender;
}

Student::~Student() {	// ����ָ����Ҫ�ͷ���
	std::cout << "..log::Student �޲�����...\n";
}

// Student �������캯��
//Student::Student(const Student& stu) {
Student::Student(Student& stu) {
	std::cout << "..log::Student �������캯��...\n";

	this->name = stu.name;
	this->id = stu.id;
	this->gender = stu.gender;
}

// ����+��д����Ĵ��麯��
void Student::work() {
	std::cout << "\n***********************************\n";
	// ��ӡ��Ϣ
	// ��ʦ����Ϣ+ѧ������Ϣ
	
	std::cout << "..��ʦ����Ϣ...\n"
		<< "...����::\t" << sp_teacher->name
		<< "...ѧ��::\t" << sp_teacher->subject
		<< "\n";

	std::cout << "..ѧ������Ϣ...\n"
		<< "...����::\t" << this->name
		<< "...ѧ��::\t" << this->id
		<< "\n";
}

// ѧ��������ʦ
void Student::setTeacher(std::shared_ptr<Teacher> sp_teacher) {
	this->sp_teacher = sp_teacher;	// ����ָ��Ŀ�������
}