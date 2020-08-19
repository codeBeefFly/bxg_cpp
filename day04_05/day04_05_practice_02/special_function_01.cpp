/*
C++ 第一个特殊函数，构造函数
初始化列表方式赋值

{} 赋值，放在类型收窄，防止精度降低

*/

#include<iostream>


class Student {		// 定义两个或两个以上的构造函数，有参，无参  
public:
	std::string name;
	int age;

	Student() {
		std::cout << "..无参构造函数...\n";
	}

	//Student(std::string name_val, int age_val) {	// 访问的就近原则，name=name; 都是形参
	//	std::cout << "..有参构造函数...\n";
	//	name = name_val;		// 不能使用 name = name; 两个都指 形参 name
	//	age = age_val;			// 不能使用 age = age;																
	//}


	// 使用初始化列表的方式解决 构造函数中形参与类成员同名的情况
	Student(std::string name, int age) :name(name), age(age) {	// name(name):外层name,类成员函数;内层name,形参
		std::cout << "..有参构造函数，初始化列表进行类成员初始化...\n";
	}

};


int main() {

	std::cout << "..in special_function_01...\n";

	Student* stu_a = new Student("jacob", 18);
	std::cout << stu_a->name << " is " << stu_a->age << " years old.\n";

	return 0;
}