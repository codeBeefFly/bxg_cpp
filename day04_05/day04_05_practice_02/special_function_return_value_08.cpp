/*

c++ 严禁函数返回内部的存放于栈内存的局部变量引用或者指针，
因为函数一旦执行完毕，那么内部的所有空间都将会被释放，
这时如果在外面操作返回值，将出现错误。所以有时候临时拷贝的工作就变得不可避免。

*/

#include<iostream>

//学生类
class Student {
public:
	std::string name;
	int age;

	Student() : name{ "unknown" }, age{ 0 }{
		std::cout << "..log::无参构造函数...\n";
	};
};

//返回普通对象
Student createStudent_normal() {
	Student stu;
	stu.name = "jacob";
	stu.age = 10;

	return stu;
}

//返回指针对象，错误写法
Student* createStudent_pointer() {
	Student stu;
	stu.name = "jacob";
	stu.age = 10;

	return &stu;			// C4172 returning address of local variable or temporary : stu 
}


// 返回指针对象，正确写法
Student* createStudent_pointer_right() {
	Student* stu = new Student;
	stu->name = "jacob";
	stu->age = 10;

	return stu;				// stu 存储的是类对象的在堆中的地址，这个地址被返回
}

//返回引用对象
Student& createStudent_reference() {
	Student stu;
	stu.name = "jacob";
	stu.age = 10;

	return stu;				// C4172 returning address of local variable or temporary : stu
}

int main() {
	
	std::cout << "..in special_function_return_value...\n";

	Student stu_a = createStudent_normal();

	Student* stu_b = createStudent_pointer();

	Student* stu_b_right = createStudent_pointer_right();

	Student& stu_c = createStudent_reference();	//听说这样写可以避免类对象拷贝

	return 0;
}

