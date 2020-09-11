/*

需求：

限定枚举在类中的使用


枚举的目的：增加程序的可读性。
枚举类型最常见也最有意义的用处之一就是用来描述状态量。


Gender::MALE, Gender::FEMALE

*/


#include <iostream>


enum class Gender
{				 
	MALE,
	FEMALE,
};



class Student
{
public:

	std::string name;
	Gender gender;

	Student();
	Student(std::string name, Gender gender);
	~Student();


};

Student::Student() : Student("unknown", Gender::MALE)
{

}


Student::Student(std::string name, Gender gender)
	: name{ name }
	, gender{ gender }{

}


Student::~Student()
{

}


int main() {

	std::cout << "..in day09_enum_class_02...\n";

	Student stu_1("jacob", Gender::MALE);
	Student stu_2("anna", Gender::FEMALE);


	// 使用三元运算符
	std::cout << "..student 1:: name::\t" << stu_1.name
		<< ", gender::\t" << ((int)stu_1.gender == 0 ? "male" : "female")
		<< "\n";

	std::cout << "..student 2:: name::\t" << stu_2.name
		<< ", gender::\t" << ((int)stu_2.gender == 0 ? "male" : "female")
		<< "\n";

	return 0;
}


/*

..in day09_enum_class_02...
..student 1:: name::    jacob, gender:: male
..student 2:: name::    anna, gender::  female

*/