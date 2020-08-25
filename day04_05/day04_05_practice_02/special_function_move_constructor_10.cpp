/*

在指针中使用移动构造函数

*/

#include <iostream>


class Student {

public:
	std::string* item;

	
	// 构造
	Student() : Student("ipad3") {
		std::cout << "..无参构造函数...\n";
	}


	// 有参构造
	Student(std::string name) : item{ new std::string("ipad3") }{
		std::cout << "..两参构造函数...\n";
	}


	// 拷贝构造函数，浅拷贝，左值匹配到拷贝构造
	Student(const Student& stu) {
		std::cout << "..拷贝构造函数...\n";
		item = stu.item;
	}


	// 移动构造函数，右值匹配到移动构造
	Student(Student&& stu) {
		std::cout << "..移动构造函数...\n";
		item = stu.item;
		stu.item = nullptr;			// 换函数放弃数据所有权
	}


};


Student createStu() {
	std::cout << "..创建对象...\n";
	Student stu;
	stu.item = new std::string("ipad3");
	return stu;
}


int main() {

	std::cout << "..in special_function_move_constructor_10...\n";

	{
		Student stu = createStu();
		std::cout << "*stu.item = " << *stu.item << "\n";
	}

	{
		Student stu = createStu();
		Student stu_b = stu;

		std::cout << "*stu_b.item = " << *stu_b.item << "\n";
		std::cout << "*stu.item = " << *stu.item << "\n";
	}

	{
		Student stu = createStu();
		Student stu_b = std::move(stu);

		std::cout << "*stu_b.item = " << *stu_b.item << "\n";
		std::cout << "*stu.item = " << *stu.item << "\n";
	}

	return 0;
}


/*

output:

..in special_function_move_constructor_10...
..创建对象...
..两参构造函数...
..无参构造函数...
..移动构造函数...
*stu.item = ipad3
..创建对象...
..两参构造函数...
..无参构造函数...
..移动构造函数...
..拷贝构造函数...
*stu_b.item = ipad3
*stu.item = ipad3
..创建对象...
..两参构造函数...
..无参构造函数...
..移动构造函数...
..移动构造函数...
*stu_b.item = ipad3
*stu.item =

*/
