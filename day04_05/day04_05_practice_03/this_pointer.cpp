/*

this的用法，链式调用。
然后函数返回自己本身，可以无限调用下去。

*/



#include <iostream>


class Student_normal {
public:
	std::string name;
	int age;

	Student_normal() : Student_normal("unknown", 10) {
		std::cout << "..log::无参构造函数...\n";
	}

	Student_normal(std::string name) : Student_normal(name, 10) {
		std::cout << "..log::一参构造函数...\n";
	}

	Student_normal(std::string name, int age) : name{ name }, age{ age }{
		std::cout << "..log::两参构造函数...\n";
	}

	~Student_normal() {
		std::cout << "..log::析构函数...\n";
	}


	void eat() {
		std::cout << "..学生吃饭...\n";
	}

	void run() {
		std::cout << "..学生跑步...\n";
	}

	void sleep() {
		std::cout << "..学生睡觉...\n";
	}

};


class Student_this {
public:
	std::string name;
	int age;

	Student_this() : Student_this("unknown", 10) {
		std::cout << "..log::无参构造函数...\n";
	}

	Student_this(std::string name) : Student_this(name, 10) {
		std::cout << "..log::一参构造函数...\n";
	}


	Student_this(std::string name, int age) : name{ name }, age{ age } {
		std::cout << "..log::两参构造函数...\n";
		this->name = name;
		this->age = age;
	}

	~Student_this() {
		std::cout << "..log::析构函数...\n";
	}

	// 返回 Student 对象
	Student_this eat() {
		std::cout << "..学生吃饭...\n";
		return *this;		// 解引用，返回类对象
	}

	Student_this run() {
		std::cout << "..学生跑步...\n";
		return *this;
	}

	Student_this sleep() {
		std::cout << "..学生睡觉...\n";
		return *this;
	}

};



class Student_this_ptr {
public:
	std::string name;
	int age;

	Student_this_ptr() : Student_this_ptr("unknown", 10) {
		std::cout << "..log::无参构造函数...\n";
	}

	Student_this_ptr(std::string name) : Student_this_ptr(name, 10) {
		std::cout << "..log::一参构造函数...\n";
	}

	Student_this_ptr(std::string name, int age) : name{ name }, age{ age } {
		std::cout << "..log::两参构造函数...\n";
		this->name = name;
		this->age = age;
	}

	~Student_this_ptr() {
		std::cout << "..log::析构函数...\n";
	}

	// 返回 Student 对象
	Student_this_ptr* eat() {
		std::cout << "..学生吃饭...\n";
		return this;		// 解引用，返回类对象
	}

	Student_this_ptr* run() {
		std::cout << "..学生跑步...\n";
		return this;
	}

	Student_this_ptr* sleep() {
		std::cout << "..学生睡觉...\n";
		return this;
	}

};


int main() {

	std::cout << "..in this_pointer...\n";

	{	std::cout << "\n**********************************\n";

		Student_normal* stu = new Student_normal("jacob", 10);
		stu->eat();
		stu->run();
		stu->sleep();

		(*stu).eat();
		(*stu).run();
		(*stu).sleep();

		Student_normal stu_b("jacob_x", 10);
		stu_b.eat();
		stu_b.run();
		stu_b.sleep();
	}

	{	std::cout << "\n**********************************\n";
		
		Student_this* stu = new Student_this("raptor", 10);
		(*stu).eat().run().sleep();			// 创建了很多对象
		
		delete stu;
	}

	{	std::cout << "\n**********************************\n";
		
		Student_this_ptr* stu = new Student_this_ptr("king", 10);
		stu->eat()->run()->sleep();			// 只创建了一个对象

		delete stu;
	}

	return 0;
}



/*

..in this_pointer...

**********************************
..log::两参构造函数...
..学生吃饭...
..学生跑步...
..学生睡觉...
..学生吃饭...
..学生跑步...
..学生睡觉...
..log::两参构造函数...
..学生吃饭...
..学生跑步...
..学生睡觉...
..log::析构函数...

**********************************
..log::两参构造函数...
..学生吃饭...
..学生跑步...
..学生睡觉...
..log::析构函数...
..log::析构函数...
..log::析构函数...
..log::析构函数...

**********************************
..log::两参构造函数...
..学生吃饭...
..学生跑步...
..学生睡觉...
..log::析构函数...

D:\W_workPlace\bxg_cpp\day04_05\build\Debug\day04_05_this_pointer.exe (process 4168) exited with code 0.
Press any key to close this window . . .

*/