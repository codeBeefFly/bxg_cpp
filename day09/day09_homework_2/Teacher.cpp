#include "Teacher.h"


// Teacher 构造函数
Teacher::Teacher() : Teacher("unknown", "unknown_subject") {
	std::cout << "..log::Teacher 无参构造...\n";
}

Teacher::Teacher(std::string name, std::string subject)
	: Human{ name }	// 使用父类有参构造初始化 name
	, subject{ subject }{
	std::cout << "..log::Teacher 有参构造...\n";
}

Teacher::~Teacher() {
	std::cout << "..log::Teacher 析构函数...\n";
}

// 定义+重写父类
void Teacher::work() {
	std::cout << "\n***********************************\n";
	// 打印信息
	// 教师的信息+学生的信息

	std::cout << "..教师的信息...\n"
		<< "...姓名::\t" << this->name
		<< "...学科::\t" << this->subject
		<< "\n";

	std::cout << "..学生的信息...\n"
		<< "...姓名::\t" << wp_student.lock()->name	// 弱指针先取得共享指针
		<< "...学号::\t" << wp_student.lock()->id
		<< "\n";
}

// 匹配学生
void Teacher::setStudent(std::shared_ptr<Student> sp_student) {
	this->wp_student = sp_student;
}