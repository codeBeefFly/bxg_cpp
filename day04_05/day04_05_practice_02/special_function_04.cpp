/*
类特殊函数--拷贝构造函数[vip]
*/


#include<iostream>


class Student {

public:
	std::string name;
	int age;


	Student() : Student("unknown", 0) {};							// 使用委托构造函数的形式初始化类成员

	Student(std::string name, int age) : name(name), age(age) {		// 委托构造函数，采用列表初始化形式初始化类成员
		std::cout << "..有二参构造函数...\n";
	}

};


int main() {
	std::cout << "..in special_function_04...\n";


	Student stu_a("jacob", 18);										// 在创建类对象的时候初始化类成员，只走一次构造函数

	Student stu_b = stu_a;											// 使用拷贝构造函数，创建一个新的类对象

	std::cout << "stu_a 的地址:: " << &stu_a << ", 姓名:: " << stu_a.name << ", 年龄:: " << stu_a.age << "\n";
	std::cout << "stu_b 的地址:: " << &stu_b << ", 姓名:: " << stu_b.name << ", 年龄:: " << stu_b.age << "\n";

	return 0;
}


/*

..in special_function_04...
..有二参构造函数...
stu_a 的地址:: 00000018BE0FFCC8, 姓名:: jacob, 年龄:: 18
stu_b 的地址:: 00000018BE0FFD18, 姓名:: jacob, 年龄:: 18

*/