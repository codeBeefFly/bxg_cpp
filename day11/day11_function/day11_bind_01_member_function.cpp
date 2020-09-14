/*

需求：

绑定类成员函数


定义一个 Student 类，类成员函数  eat(string food)


定义一个全局 printStudent 函数，接收函数对象+类对象


使用 函数对象 + bind + 函数对象&&bind 方式调用 类成员函数


*/


#include <iostream>
#include <functional>


class Student {

public:
	void eat(std::string food) {
		std::cout << "..jacob is eating " << food << "...\n";
	}

};


void printStudent(std::function<void()> f_eat) {
	f_eat();
}


// 类成员语法  (函数对象+类+参数, 类对象变量, 参数变量);
void printStudent_2(std::function<void(Student, std::string)> f_eat, Student student, std::string food) {
	f_eat(student, food);
}


void printStudent_3(std::function<void(std::string)> f_eat) {
	f_eat("apple");
}



int main() {
	std::cout << "..in day11_bind_01_member_function...\n";

	// 使用 function 函数对象调用 类成员函数
	std::function<void(Student, std::string)> f_stu_eat = &Student::eat;

	Student stu_jacob;

	f_stu_eat(stu_jacob, "banana");

	printStudent_2(f_stu_eat, stu_jacob, "apple");

	// 使用bind + auto 自动推导 绑定 类成员函数
	Student stu_raptor;
	auto p_stu_eat = std::bind(&Student::eat, stu_raptor, "orange");
	p_stu_eat();

	// 使用 printStudent 调用类成员函数 参数为 function 对象
	//printStudent(f_stu_eat(stu_jacob, "grape"));	// 不行 无参类型的

	// 使用 printStudent 调用类成员函数 参数为 bind 函数
	std::function<void()> f_stu_eat_null = std::bind(&Student::eat, stu_raptor, "grape");
	printStudent(f_stu_eat_null);

	return 0;
}


/*

output

..in day11_bind_01_member_function...
..jacob is eating banana...
..jacob is eating apple...
..jacob is eating orange...
..jacob is eating grape...

*/
