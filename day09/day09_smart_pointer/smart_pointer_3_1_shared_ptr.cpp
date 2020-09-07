/*

需求：

验证 shared_ptr 的用法功能

1. 创建一个 Student 类，成员 name，有构造析构

2. 在 main 中用常规方式创建一个 Student 类指针，在堆内存中，并使用有参构造初始化类对象

3. 使用 shared_ptr 对象包装 Student 类对象

4. 使用 shared_ptr 对象包装 shared_ptr 对象

5. shared_ptr 可以拷贝，可以移动

5. 使用 shared_ptr 移动一个 shared_ptr

6. 使用一个 shared_ptr 取值，三种方式 get()，

7. 释放，释放，释放指针

*/


#include <iostream>
#include <memory>


class Student {


public:

	std::string name;

	Student() = default;
	Student(std::string name) : name{ name } {
		std::cout << "..log::有参构造函数...\n";
	}
	~Student() {
		std::cout << "..log::析构函数...\n";
	}

};


int main() {

	std::cout << "..in smart_pointer_3_1_shared_ptr...\n";

	// 一般形式在堆中创建对象
	Student* student = new Student("jacob");

	// 创建一个共享指针，并包裹学生对象，用有参构造的方式
	std::shared_ptr<Student> s_ptr_stu_1(student);
	
	std::cout << "..s_ptr_stu_1 计数::\t" << s_ptr_stu_1.use_count() << "\n";

	// 创建一个共享指针，并拷贝共享指针
	std::shared_ptr<Student> s_ptr_stu_2 = s_ptr_stu_1;

	std::cout << "..s_ptr_stu_1 计数::\t" << s_ptr_stu_1.use_count() << "\n";
	std::cout << "..s_ptr_stu_2 计数::\t" << s_ptr_stu_2.use_count() << "\n";


	// 创建一个共享指针，并移动共享指针
	std::shared_ptr<Student> s_ptr_stu_3 = std::move(s_ptr_stu_2);

	std::cout << "..s_ptr_stu_1 计数::\t" << s_ptr_stu_1.use_count() << "\n";
	std::cout << "..s_ptr_stu_2 计数::\t" << s_ptr_stu_2.use_count() << "\n";
	std::cout << "..s_ptr_stu_3 计数::\t" << s_ptr_stu_3.use_count() << "\n";


	// 取值，三种方式
	// 智能指针 s_ptr_stu_3
	std::cout << "..学生姓名::\t" << s_ptr_stu_3.get()->name << "\n";
	std::cout << "..学生姓名::\t" << (*s_ptr_stu_3).name << "\n";
	std::cout << "..学生姓名::\t" << s_ptr_stu_3->name << "\n";

	//// 智能指针 s_ptr_stu_2，报错，空指针
	//std::cout << "..学生姓名::\t" << s_ptr_stu_2.get()->name << "\n";	
	//std::cout << "..学生姓名::\t" << (*s_ptr_stu_2).name << "\n";
	//std::cout << "..学生姓名::\t" << s_ptr_stu_2->name << "\n";


	// 智能指针 s_ptr_stu_1
	std::cout << "..学生姓名::\t" << s_ptr_stu_1.get()->name << "\n";
	std::cout << "..学生姓名::\t" << (*s_ptr_stu_1).name << "\n";
	std::cout << "..学生姓名::\t" << s_ptr_stu_1->name << "\n";


	// 释放智能指针
	s_ptr_stu_1.reset();	// 重新绑定指针到空指针
	std::cout << ".. s_ptr_stu_1 计数::\t" << s_ptr_stu_1.use_count() << "\n";
	std::cout << ".. s_ptr_stu_2 计数::\t" << s_ptr_stu_2.use_count() << "\n";
	std::cout << ".. s_ptr_stu_3 计数::\t" << s_ptr_stu_3.use_count() << "\n";

	s_ptr_stu_3.reset();	// 重新绑定指针到空指针
	std::cout << ".. s_ptr_stu_1 计数::\t" << s_ptr_stu_1.use_count() << "\n";
	std::cout << ".. s_ptr_stu_2 计数::\t" << s_ptr_stu_2.use_count() << "\n";
	std::cout << ".. s_ptr_stu_3 计数::\t" << s_ptr_stu_3.use_count() << "\n";


	return 0;
}


/*


output:

..in smart_pointer_3_1_shared_ptr...
..log::有参构造函数...
..s_ptr_stu_1 计数::    1
..s_ptr_stu_1 计数::    2
..s_ptr_stu_2 计数::    2
..s_ptr_stu_1 计数::    2
..s_ptr_stu_2 计数::    0
..s_ptr_stu_3 计数::    2
..学生姓名::    jacob
..学生姓名::    jacob
..学生姓名::    jacob
..学生姓名::    jacob
..学生姓名::    jacob
..学生姓名::    jacob
.. s_ptr_stu_1 计数::   0
.. s_ptr_stu_2 计数::   0
.. s_ptr_stu_3 计数::   1
..log::析构函数...
.. s_ptr_stu_1 计数::   0
.. s_ptr_stu_2 计数::   0
.. s_ptr_stu_3 计数::   0


*/