#include "Student.h"

Student::Student() : Student("unknown_name", "00000", nullptr) {

}

Student::Student(std::string name, std::string id, Teacher* teacher)
	: name{ name }
	, id{ id } 
	, teacher{ new Teacher } {
	std::cout << "..log::Student ���캯��...\n";
}


Student::~Student() {
	std::cout << "..log::Student ��������...\n";
}


//TODO	������ôд��ֻ����������
//std::istream& operator>>(std::istream& in, Student& student, Teacher& teacher) {	// ʹ�� bind ������
//	//student.teacher = teacher;
//	//in >> student.name >> student.id >> ;
//	in >> "..function not finished...\n";
//	return in;
//}


std::istream& operator>>(std::istream& in, Student& student) {
	in >> student.name >> student.id;
	//in >> student.name >> student.id >> student.teacher->subject;

	return in;
}


std::ostream& operator<<(std::ostream& out, Student& student) {
	out << student.name << ", " << student.id << ", " << student.teacher->subject << "\n";
	
	return out;
}