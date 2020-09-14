/*

需求：

定义一个 Student 类，里面有 run eat 函数

定义一个全局的函数 printStu，接收函数对象+类对象作为参数

在main 中使用函数 printStu 调用 类中的两个参数

*/



#include <iostream>
#include <functional>


class Student {
public:
	void eat(){
		std::cout << "jacob is eating...\n";
	}

	void run() {
		std::cout << "jacob is runnning...\n";
	}
	void sleep() {
		std::cout << "jacob is sleeping...\n";
	}
};



void printStudent(Student student, std::function<void(Student)> f_student) {
	f_student(student);
}

void printStudent(Student* student, std::function<void(Student*)> f_student) {
	f_student(student);
}

void printStudent(Student& student, std::function<void(Student&)> f_student) {
	f_student(student);
}



int main() {

	std::cout << "..in day11_function_object_03_functionCall...\n";

	// 创建学生类的函数对象
	std::function<void(Student)> f_sleep = &Student::sleep;
	std::function<void(Student*)> f_eat = &Student::eat;
	std::function<void(Student&)> f_run = &Student::run;

	// 通过回调函数调用学生类对象函数，首先创建学生类对象
	Student stu_jacob;
	printStudent(stu_jacob, f_sleep);

	printStudent(&stu_jacob, f_eat);

	printStudent(stu_jacob, f_run);


	return 0;

}


/*

output


..in day11_function_object_03_functionCall...
jacob is sleeping...
jacob is eating...
jacob is runnning...


*/