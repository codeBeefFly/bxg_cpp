/*

需求：

如果在继承状态下，子类中的成员又含有其他类的对象属性，那么他们之间的构造很析构调用顺序，遵循以下原则：

a. 先调用父类的构造函数,再调用组合对象的构造函数,最后调用自己的构造函数;

b. 先调用自己的析构函数,再调用组合对象的析构函数,最后调用父类的析构函数。


创建一个person类

创建一个A类

创建一个学生类继承person类

所有类都只有构造/析构函数

*/


#include <iostream>


class Person {

public:

	Person() {
		std::cout << "..Person构造函数...\n";
	}

	~Person() {
		std::cout << "..Person析构函数...\n";
	}

};


class A {

public:

	A() {
		std::cout << "..A构造函数...\n";
	}

	~A() {
		std::cout << "..A析构函数...\n";
	}

};


class Student : public Person{

public:

	Student() {
		std::cout << "..Student构造函数...\n";
	}

	~Student() {
		std::cout << "..Student析构函数...\n";
	}

public:
	A a;
};



int main() {

	std::cout << "..in inherit_combined...\n";

	Student stu;

	return 0;

}



/*

a. 先调用父类的构造函数,再调用组合对象的构造函数,最后调用自己的构造函数;

b. 先调用自己的析构函数,再调用组合对象的析构函数,最后调用父类的析构函数。


..in inherit_combined...
..Person构造函数...
..A构造函数...
..Student构造函数...
..Student析构函数...
..A析构函数...
..Person析构函数...


*/