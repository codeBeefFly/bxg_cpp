/*
C++ 第二个特殊函数，委托构造函数
初始化列表方式赋值

{} 赋值，放在类型收窄，防止精度降低

*/

#include<iostream>


class Student {		// 定义两个或两个以上的构造函数，有参，无参  
public:
	std::string name;
	int age;

	/*
	
	
	/// 初始化列表方式赋值+默认值，一般的构造函数写法
	//1. 无参构造函数
	Student() {
		std::cout << "..无参构造函数...\n";
		// 初始默认值
		name = "unknown";
		age = 0;
	}

	//2. 有参构造函数，1个参数
	Student(std::string name) : name(name), age(18) {	// 初始化列表赋值，age初始化默认值
		std::cout << "..有参构造函数，1个参...\n";
	}

	//3. 有参构造函数，2个参数
	Student(std::string name, int age) : name(name), age(age) {
		std::cout << "..有参构造函数，2个参数...\n";
	}
	
	
	*/


	///委托构造函数的写法
	Student() : Student("unknown", 18) {							// 这个无参的构造函数委托一个两个参的构造函数，一般是无参委托有参
		std::cout << "..无参构造函数，委托写法...\n";
	}

	Student(std::string name) : Student(name, 18) {					// 这个1个参的构造函数委托一个两个参的构造函数
		std::cout << "..有参构造函数，1个参，委托写法...\n";
	}

	//委托构造函数，按一般列表初始化的方式写
	Student(std::string name, int age) : name(name), age(age) {		// 这个是两个参数的委托构造函数
		std::cout << "..有参构造函数，2个参，委托写法...\n";
	}

};


int main() {

	std::cout << "..in special_function_02...\n";


	// 无参
	Student stu_a;

	// 1个参
	Student stu_b("jacob");

	// 两个参
	Student stu_c("raptor", 19);
	return 0;
}