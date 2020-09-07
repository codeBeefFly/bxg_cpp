/*

需求

智能指针管理的一般都是堆内存指针

*/


#include <iostream>
#include <memory>


class Student {

public:

	std::string name;
	
	Student() {
		std::cout << "..log Student 无参构造函数...\n";
	}
	Student(std::string name) : name{ name } {
		std::cout << "..log Student 有参构造函数...\n";
	}
	~Student() {
		std::cout << "..log Student 析构函数...\n";
	}

};


int main() {

	std::cout << "..in smart_pointer_2...\n";

	{
		// 声明一个唯一指针
		std::unique_ptr<int> u_ptr_int;

		// 创建一个一般形式的int 指针
		int* ptr_int = new int(3);

		// 管理指针
		/*
		
		替换被管理对象。

		1) 给定指向 *this 所管理对象的指针 current_ptr ，进行下列行动，以此顺序：
			1. 保存当前指针的副本 old_ptr = current_ptr
			2. 以参数重写当前指针 current_ptr = ptr
			3. 若旧指针非空，则删除先前管理的对象 if(old_ptr != nullptr) get_deleter()(old_ptr) 。
		
		*/
		u_ptr_int.reset(ptr_int);

		std::cout << ".. u_ptr_int.get() = " << *u_ptr_int.get() << "\n";	// get() 返回 ptr，.. u_ptr_int.get() = 3


	}


	{
		// 在堆内存创建一个 Student 类型对象并初始化
		Student* student_1 = new Student("jacob");
		Student* student_2 = new Student("raptor");

		// 声明一个唯一指针并接管这个student指针
		std::unique_ptr<Student> u_ptr_student_1(student_1);	// 函数走完 唯一指针自动释放被管理的指针

		// 用reset 方法
		/*
		
		reset() 方法，可以有参数，可以没有参数
		有参数会，释放以前的指针指向的空间，然后转向现在的指针
		没有参数，释放以前的指针，变成空指针


		//可以使用reset显式释放内存。
		p3.reset();

		//重新绑定新的指针
		p3.reset(new int(6));	// p3 是唯一指针，重新绑定指针后唯一指针就会帮助接管这个指针
		

		*/
		std::unique_ptr<Student> u_ptr_student_2;	
		u_ptr_student_2.reset(student_2);


		std::cout << ".. *u_ptr_student_1->name::\t" << u_ptr_student_1->name << "\n";
		std::cout << ".. *u_ptr_student_2->name::\t" << u_ptr_student_2->name << "\n";

	}

	return 0;
}


/*


output:

..in smart_pointer_2...
.. u_ptr_int.get() = 3
..log Student 有参构造函数...
..log Student 有参构造函数...
.. *u_ptr_student_1->name::     jacob
.. *u_ptr_student_2->name::     raptor
..log Student 析构函数...
..log Student 析构函数...


*/