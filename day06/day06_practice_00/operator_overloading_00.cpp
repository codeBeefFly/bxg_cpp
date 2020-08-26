/*

使用运算符重载，将将两个对象的相加，返回他们的年龄总和

这段代码将要体现运算符重载的两种形式
1. 运算符重载函数做类成员函数  operator+()
2. 运算符重载函数做全局定义函数 operator-()

*/



#include<iostream>
#include<vector>

class Student {

public:

	int age;

	std::vector<int> scores{ 1, 2, 4, 8 };

	Student() : Student(0) {
		std::cout << "..无参构造函数...\n";
	}

	Student(int age) : age{ age } {
		std::cout << "..有参构造函数...\n";
	}

	int operator+(Student& stu) {				// +运算符重载，类成员函数形式	
		return this->age + stu.age;
	}


	//std::ostream& operator<<(std::ostream& out, std::vector<int>& scores) {
	//	for (int score : scores) {
	//		out << score << "\t";
	//	}
	//	return out;
	//}

};


// -运算符重载，全局函数定义形式
int operator-(Student& stu1, Student& stu2) {	// 不发生拷贝用 &
	return stu1.age - stu2.age;
}


// <<运算符重载，全局函数定义形式，两个参数都是引用传递，返回引用，可以运行
std::ostream& operator<<(std::ostream& out, std::vector<int>& scores) {
	for (int score : scores) {
		out << score << "\t";
	}

	return out;
}

// *运算符重载，全局函数定义形式
Student operator*(Student& stu1, Student& stu2) {
	Student stu3;
	stu3.age = stu1.age * stu2.age;

	return stu3;
}

int main() {

	std::cout << "..in operator_overloading_00...\n";

	Student s1(10), s2(20);
	std::cout << "..学生 s1 与 s2 年龄总和 :: " << s1 + s2 << "\n";	// 使用运算符重载，类成员函数形式
	std::cout << "..学生 s1 与 s2 年龄之差 :: " << s1 - s2 << "\n";	// 使用运算符重载，全局函数定义形式

	Student s3 = s1 * s2;
	std::cout << "..学生 s3 的年龄 = s1 的 * s2 的 :: " << s3.age << "\n";	// 使用运算符重载，全局函数定义形式

	//std::cout << s1.scores << "\n";
	
	std::vector<int> scores{ 1, 2, 4, 8 };
	std::cout << scores << "\n";


	return 0;
}


/*

output

..in operator_overloading_00...
..有参构造函数...
..有参构造函数...
..学生 s1 与 s2 年龄总和 :: 30



..in operator_overloading_00...
..有参构造函数...
..有参构造函数...
..学生 s1 与 s2 年龄总和 :: 30
..学生 s1 与 s2 年龄之差 :: -10

*/