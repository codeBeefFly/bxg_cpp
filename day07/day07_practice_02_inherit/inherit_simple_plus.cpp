/*

需求

定义 person 类
public
成员：name
private
成员：age
protect：
函数：
eat


定义 student 类，继承 person类
public:
扩展的 read 函数

*/





#include <iostream>

class Person {
public:
	std::string name;

private:
	int age;

protected:
	void eat() {
		std::cout << name << " eat food\n";
	}

 };


class Student : public Person{

public:
	void read() {
		std::cout << name << " read book\n";
	}

 };





int main() {

	std::cout << "..in inherit_simple_plus...\n";

	Person p;
	p.name = "person";
	//p.age // 不行
	//p.eat()

	Student s;
	s.name = "student";
	s.read();


	return 0;
}