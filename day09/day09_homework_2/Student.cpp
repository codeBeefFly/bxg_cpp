#include "Student.h"



// Student 构造+析构函数
//Student::Student() : Student("unknown", "100xx", Gender::MALE) {
//	std::cout << "..log::Student 无参构造...\n";
//}

Student::Student(){
	std::cout << "..log::Student 无参构造...\n";
}

//Student::Student(std::string name, std::string id, Gender gender)
//	: Human{ name }		// 调用父类的有参构造
//	, id{ id }
//	, gender{ gender }{
//	std::cout << "..log::Student 有参构造...\n";
//}

Student::Student(std::string name, std::string id, Gender gender)
	: id{ id } {
	std::cout << "..log::Student 有参构造...\n";
	this->name = name;
	this->gender = gender;
}

Student::~Student() {	// 共享指针需要释放吗
	std::cout << "..log::Student 无参析构...\n";
}

// Student 拷贝构造函数
//Student::Student(const Student& stu) {
Student::Student(Student& stu) {
	std::cout << "..log::Student 拷贝构造函数...\n";

	this->name = stu.name;
	this->id = stu.id;
	this->gender = stu.gender;
}

// 定义+重写父类的纯虚函数
void Student::work() {
	std::cout << "\n***********************************\n";
	// 打印信息
	// 教师的信息+学生的信息
	
	std::cout << "..教师的信息...\n"
		<< "...姓名::\t" << sp_teacher->name
		<< "...学科::\t" << sp_teacher->subject
		<< "\n";

	std::cout << "..学生的信息...\n"
		<< "...姓名::\t" << this->name
		<< "...学号::\t" << this->id
		<< "\n";
}

// 学生分配老师
void Student::setTeacher(std::shared_ptr<Teacher> sp_teacher) {
	this->sp_teacher = sp_teacher;	// 共享指针的拷贝函数
}