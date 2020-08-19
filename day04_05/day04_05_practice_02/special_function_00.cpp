/*
C++ 第一个特殊函数，构造函数
*/

#include<iostream>


class Student {
public:
	std::string name;
	int age;

	Student() {						// 无参构造函数
		std::cout << "..无参构造函数...\n";
	}

	Student(std::string name_val) {
		std::cout << "..有参构造函数...\n";
	}
};


int main() {

	std::cout << "..in special_function_00...\n";

	Student stu;					// 在栈内存开辟空间
	stu.name = "jacob";

	Student* stu_b = new Student;	// 在堆内存开辟空间，创建一个Student指针指向此空间
	//Student* stu_b = new Student();	// 在堆内存开辟空间，创建一个Student指针指向此空间，或者这样写，加一个小括号
	//stu_b->name = "jacob";
	(*stu_b).name = "raptor";		// 指针解引用得到内存地址
	(*stu_b).age = 18;


	Student* stu_c = new Student("king");
	(*stu_c).age = 18;


	Student stu_d();

	return 0;
}