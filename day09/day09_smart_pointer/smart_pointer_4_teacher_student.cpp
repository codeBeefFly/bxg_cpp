/*

需求：

1. 创建一个 teacher 类，
	1. 类中私有成员 智能指针 Student 类型
	2. 公共成员
		1. setStu -- 接收 shared_ptr
		2. 

*/



#include <iostream>
#include <memory>

class Teacher;
class Student;


class Teacher {

private:
	// 创建学生类型共享指针
	std::shared_ptr<Student> s_ptr_student;

public:
	Teacher() {
		std::cout << "..log::Teacher 构造...\n";
	}
	~Teacher() {
		std::cout << "..log::Teacher 析构...\n";
	}

	void setStudent(std::shared_ptr<Student> s_ptr_student) {
		this->s_ptr_student = s_ptr_student;	// 共享指针可以拷贝
	}

};



class Student {

private:
	// 创建学生类型共享指针
	std::shared_ptr<Teacher> s_ptr_teacher;

public:
	Student() {
		std::cout << "..log::Student 构造...\n";
	}
	~Student() {
		std::cout << "..log::Student 析构...\n";
	}

	void setTeacher(std::shared_ptr<Teacher> s_ptr_teacher) {
		this->s_ptr_teacher = s_ptr_teacher;	// 共享指针可以拷贝
	}

};



int main() {

	std::cout << "..in smart_pointer_4_teacher_student...\n";

	// 普通方式创建 Teacher Student 类对象
	Teacher* teacher = new Teacher;
	Student* student = new Student;

	// 使用共享指针包裹普通指针
	std::shared_ptr<Teacher> s_ptr_teacher(teacher);
	std::shared_ptr<Student> s_ptr_Student(student);

	// 学生老师互配
	teacher->setStudent(s_ptr_Student);
	student->setTeacher(s_ptr_teacher);



	return 0;

}


/*

output

只有构造 没有析构

..in smart_pointer_4_teacher_student...
..log::Teacher 构造...
..log::Student 构造...


*/