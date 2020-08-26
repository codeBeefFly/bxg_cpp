/*

需求：

合计学生a与学生b的零用钱之和，使用运算符重载

设计

1. + 运算符重载函数为类成员函数

2. - 运算符重载为全局函数


*/

#include <iostream>


class Student {

public:

	int money;


	Student() : Student(money) {
		std::cout << "..无参构造函数...\n";
	}


	Student(int money) : money{ money } {
		std::cout << "..有参构造函数...\n";
	}


	// operator+
	Student& operator+(Student& b) {
		return Student(this->money + b.money);		// 返回一个学生对象，这个学生对象中的 money 为另外两个学生对象的 money和
	}

	// operator*，错误写法
	//int& operator*(Student& b) {					// &返回引用，应该是一个左值
	//	return this->money * b.money;				// 这是一个右值
	//}

	int&& operator*(Student& b) {					// &返回引用，应该是一个左值
		return this->money * b.money;				// 这是一个右值
	}

	float operator/(Student& b) {
		return this->money / b.money;
	}
};


Student& operator-(Student& a, Student& b) {
	return Student(a.money - b.money);
}


int main(){

	std::cout << "..in student_money_operator_overload...\n";

	Student a(20), b(30);
	Student c = a + b;
	Student d = a - b;

	std::cout << "c has money :: " << c.money << "\n";
	std::cout << "d has money :: " << d.money << "\n";

	
	return 0;
}



/*

..in student_money_operator_overload...
..有参构造函数...
..有参构造函数...
..有参构造函数...
..有参构造函数...
c has money :: 50
d has money :: -10

*/