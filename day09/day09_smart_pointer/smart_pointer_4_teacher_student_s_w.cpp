/*

需求：

1. 创建一个 Teacher 类
	1. 私有区：Student 类型 共享指针
	2. 公有区：构造，析构，setStudent

2. 创建一个 Student 类
	1. 私有区：Teacher 类型 共享指针
	2. 公有区：构造，析构，setTeacher


为了避免`shared_ptr`的环形引用问题，需要引入一个弱指针weak_ptr`，
它指向一个由`shared_ptr`管理的对象而不影响所指对象的生命周期，
也就是将一个`weak_ptr`绑定到一个`shared_ptr`不会改变`shared_ptr`的引用计数。
不论是否有`weak_ptr`指向，一旦最后一个指向对象的`shared_ptr`被销毁，
对象就会被释放。从这个角度看，`weak_ptr`更像是`shared_ptr`的一个助手而不是智能指针。

week_ptr 不会增加shared_ptr的计数，并且可以接受shared_ptr


*/



#include <iostream>
#include <memory>


class Teacher;
class Student;


class Teacher {

private:
	
	std::shared_ptr<Student> s_ptr_student;

public:
	
	Teacher() {
		std::cout << "..log::Teacher 构造...\n";
	}
	~Teacher() {
		std::cout << "..log::Teacher 析构...\n";
	}

	void setStudent(std::shared_ptr<Student> s_ptr_student) {
		this->s_ptr_student = s_ptr_student;
	}


};


class Student {

private:

	std::weak_ptr<Teacher> s_ptr_teacher;	// 只需要在成员中声明 weak_ptr 其他的都是 shared_ptr

public:

	Student() {
		std::cout << "..log::Student 构造...\n";
	}
	~Student() {
		std::cout << "..log::Student 析构...\n";
	}

	void setTeacher(std::shared_ptr<Teacher> s_ptr_Teacher) {
		this->s_ptr_teacher = s_ptr_Teacher;
	}


};


int main() {

	std::cout << "..in smart_pointer_4_teacher_student_s_w...\n";

	// 普通方式创建 Teacher Student 对象，在堆空间
	Teacher* teacher = new Teacher;
	Student* student = new Student;

	// 使用共享指针包裹普通指针
	std::shared_ptr<Teacher> s_ptr_teacher(teacher);	// Student 类中是 weak_ptr<Teacher>
	std::shared_ptr<Student> s_ptr_student(student);

	// 老师学生互配
	teacher->setStudent(s_ptr_student);
	student->setTeacher(s_ptr_teacher);


	return 0;

}



/*

output

..in smart_pointer_4_teacher_student_s_w...
..log::Teacher 构造...
..log::Student 构造...
..log::Teacher 析构...
..log::Student 析构...

*/