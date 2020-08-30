/*

需求

拷贝赋值运算符重载

移动赋值运算符重载，需要类成员为指针类型

*/


#include <iostream>
#include <vector>


class Student
{
public:

	std::string name;
	int age;

	Student();
	Student(std::string name, int age);
	~Student();

	//Student& operator=(Student& stu_right);		// 拷贝赋值运算符重载
	void operator=(const Student& stu_right);		// 拷贝赋值运算符重载

	//Student& operator=(Student&& stu_right) {};	// 移动赋值运算符重载
	void operator=(Student&& stu_right0);			// 移动赋值运算符重载

};


Student::Student() : Student("unknown", 0)
{
	std::cout << "..无参构造函数...\n";
}


Student::Student(std::string name, int age) 
	: name{ name }
	, age{ age } {
	std::cout << "..有参构造函数...\n";
}


Student::~Student()
{
	std::cout << "..析构函数...\n";
}


// 拷贝赋值运算符，最好在参数前加上 const ,
//Student& Student::operator=(Student& stu_right) {
void Student::operator=(const Student& stu_right) {		// 发生如 stu1 = stu2; 代码时，走这个函数。
	std::cout << "..拷贝赋值运算符函数重载...\n";

	// 类成员拷贝赋值代码，浅拷贝
	this->name = stu_right.name;
	this->age = stu_right.age;

	// 类成员拷赋值制代码，深拷贝，当类中成员存在动态成员时（指针），浅拷贝会出现问题，使用深拷贝
	// 这里不用深拷贝，因为类中成员没有动态成员（指针）

}


void Student::operator=(Student&& stu_right) {			// 移动赋值运算符重载
	std::cout << "..移动赋值运算符函数重载...\n";

	// 类成员拷贝赋值代码，浅拷贝
	this->name = stu_right.name;
	this->age = stu_right.age;

}




int main() {

	std::cout << "..in operator_overload_copy_move...\n";

	Student stu1{ "jacob", 10 };
	Student stu2{ "raptor", 20 };
	Student stu3{ "king", 30 };

	std::cout << "..stu1.name::\t" << stu1.name << ", stu1.age::\t" << stu1.age << ".\n";
	std::cout << "..stu2.name::\t" << stu2.name << ", stu2.age::\t" << stu2.age << ".\n";
	std::cout << "..stu3.name::\t" << stu3.name << ", stu3.age::\t" << stu3.age << ".\n";

	stu1 = stu2;

	std::cout << "..stu1.name::\t" << stu1.name << ", stu1.age::\t" << stu1.age << ".\n";
	std::cout << "..stu2.name::\t" << stu2.name << ", stu2.age::\t" << stu2.age << ".\n";
	std::cout << "..stu3.name::\t" << stu3.name << ", stu3.age::\t" << stu3.age << ".\n";

	stu1 = std::move(stu3);

	std::cout << "..stu1.name::\t" << stu1.name << ", stu1.age::\t" << stu1.age << ".\n";
	std::cout << "..stu2.name::\t" << stu2.name << ", stu2.age::\t" << stu2.age << ".\n";
	std::cout << "..stu3.name::\t" << stu3.name << ", stu3.age::\t" << stu3.age << ".\n";




	return 0;
}


