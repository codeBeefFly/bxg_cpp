/*

需求：

练习纯虚函数


有一个纯虚函数的类就是抽象类

抽象类不能创建对象，因为里面有纯虚函数，纯虚函数没有函数体

纯虚类中可有普通的成员函数

如果一个子类继承了抽象类，那么必须重写所有抽象类中所有纯虚函数，否则也为抽象函数

纯虚函数往往承担起了这部分功能

*/		   


#include <iostream>

class Virtual_Animal {		// 全是纯虚函数的抽象类
public:
	
	virtual void eat() = 0;
	virtual void run() = 0;
	virtual void sleep() = 0;
};


class Fish : public Virtual_Animal {
public:
	void eat() {
		std::cout << "..fish eat algae...\n";
	}

	void run() {
		std::cout << "..fish swim with fins...\n";
	}

	void sleep() {
		std::cout << "..fish sleep with eyes open...\n";
	}
};


class Cat : public Virtual_Animal {		// 子类必须要实现 base 虚函数的所有成员函数才能够创建对象。不然依然是纯虚函数
public:
	void eat() {
		std::cout << "..Cat eats meat...\n";
	}

	void run() {
		std::cout << "..Cat run with four legs...\n";
	}

	//void sleep() {
	//	std::cout << "..Cat sleep curl up all the day...\n";
	//}
};



class X {		// 只有一个纯虚函数的抽象类
public :
	virtual void A() {
		std::cout << "....aaaa" << std::endl;
	}

	void B() {
		std::cout << "...bbbb" << std::endl;
	}
};


int main() {

	std::cout << "..in virtual_fuction_pure_virtual_function...\n";

	Virtual_Animal* va_1 = new Fish();
	va_1->eat();
	va_1->run();
	va_1->sleep();

	//Virtual_Animal* va_2 = new Cat();	// object of abstruct class type Cat is not allowed, pure virtual function virtual void sleep has no overrider.
	//va_2->eat();
	//va_2->run();
	//va_2->sleep();



	return 0;
}