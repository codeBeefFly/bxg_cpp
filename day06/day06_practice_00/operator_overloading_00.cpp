/*

使用运算符重载，将将两个对象的相加，返回他们的年龄总和

*/



#include<iostream>

class Student {

public:

	int age;

	Student() : Student(0) {
		std::cout << "..无参构造函数...\n";
	}

	Student(int age) : age{ age } {
		std::cout << "..有参构造函数...\n";
	}

	int operator+(Student& stu) {
		return this->age + stu.age;
	}
};



int main() {

	std::cout << "..in operator_overloading_00...\n";

	Student s1(10), s2(20);
	std::cout << "..学生 s1 与 s2 年龄总和 :: " << s1 + s2 << "\n";	// 使用运算符重载

	return 0;
}


/*

output

..in operator_overloading_00...
..有参构造函数...
..有参构造函数...
..学生 s1 与 s2 年龄总和 :: 30

*/