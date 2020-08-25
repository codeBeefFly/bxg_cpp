/*

定义一个学生类，存在分数  (int * 类型) ， 先创建张三的实例 ，然后通过移动构造的方式创建李四。

1. 函数返回
2. move函数方式。

*/


#include <iostream>

class Student {

public:
	std::string name;
	int* score = nullptr;


	// 无参构造
	Student() : Student("unknown", 0) {
		std::cout << "..log::无参构造...\n";
	}

	// 一参构造
	Student(std::string name) : Student(name, 0) {
		std::cout << "..log::一参构造...\n";
	}

	// 两参构造
	Student(std::string name, int score) : name{ name }, score{ new int{score} } {
		std::cout << "..log::两参构造...\n";
	}

	// 拷贝构造，赋值左值
	Student(const Student& stu) {
		std::cout << "..log::拷贝构造...\n";

		//name = stu.name;
		//score = stu.score;		// 地址赋地址

		name = stu.name;
		score = new int(*stu.score);
	}

	// 移动构造，赋值右值
	Student(Student&& stu) {
		std::cout << "..log::移动构造...\n";

		name = stu.name;
		score = stu.score;
		score = nullptr;
	}

	// 析构
	~Student() {
		std::cout << "..log::析构函数...\n";
		delete score;
		score = nullptr;
	}

};


int main() {
	
	std::cout << "..in student_class_move_constructor...\n";

	Student stu_a("zhangsan", 10);
	Student stu_b = std::move(stu_a);		// 移动拷贝，原对象再获取以前的指针值会报错

	std::cout << "stu_a.name:: " << stu_a.name << ", *stu_a.score:: " << *stu_a.score << "\n";
	std::cout << "stu_b.name:: " << stu_b.name << ", *stu_b.score:: " << *stu_b.score << "\n";	// 不能获取原对象的指针值


	return 0;
}


/*

..in student_class_move_constructor...
..log::两参构造...
..log::移动构造...
stu_a.name:: zhangsan, *stu_a.score:: 10
stu_b.name:: zhangsan, *stu_b.score::
D:\W_workPlace\bxg_cpp\day04_05\build\Debug\day04_05_homework_student_class_move_constructor.exe (process 7268) exited with code -1073741819.
Press any key to close this window . . .


*/