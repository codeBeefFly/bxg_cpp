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


	// 拷贝构造函数，浅拷贝
	Student(const Student& stu) {
		std::cout << "..拷贝构造函数...\n";
		item = stu.item;
	}


	// 移动构造函数
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

	Student stu = createStu();

	return 0;
}
