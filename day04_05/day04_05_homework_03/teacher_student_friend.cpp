/*

练习作业：

教师关爱学生，视学生为自己的朋友，这是常有的事，
教师有自己的厨房，允许学生闲暇时过来 cooking ， 
请使用友元的概念，设计该行为。

*/


#include <iostream>

class Teacher {

private:

	std::string kitchen;


public:

	Teacher() {
		std::cout << "..无参构造函数...\n";
	}

	Teacher(std::string kitchen) : kitchen{ kitchen } {
		std::cout << "..有参构造函数...\n";
	}

	//void cooking() {
	//	std::cout << "..cooking in the [" << kitchen << "]\n";
	//}

	friend class Student;

};


class Student {

public:

	void cooking(Teacher t) {	// 可以使用友元类中的变量
		std::cout << "..cooking in the [" << t.kitchen << "]\n";
	}

};


int main() {

	std::cout << "..teacher_student_friend...\n";

	Teacher t("teacher's kitchen");

	Student s;
	s.cooking(t);

	return 0;
}


/*

..teacher_student_friend...
..有参构造函数...
..cooking in the [teacher's kitchen]

*/