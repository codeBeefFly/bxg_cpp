#include "Student.h"

Student::Student() : Student("unknown_name", "00000", nullptr) {

}

Student::Student(std::string name, std::string id, Teacher* teacher)
	: name{ name }
	, id{ id } 
	, teacher{ new Teacher } {
	std::cout << "..log::Student 构造函数...\n";
}


Student::~Student() {
	std::cout << "..log::Student 析构函数...\n";
}


//TODO	不能这么写，只有两个参数
//std::istream& operator>>(std::istream& in, Student& student, Teacher& teacher) {	// 使用 bind 函数？
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