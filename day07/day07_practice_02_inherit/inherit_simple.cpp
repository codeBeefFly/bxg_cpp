/*

简单的继承
定义一个父类，父类有 int money
子类继承公共父类
子类调用父类 int money

*/



#include <iostream>

// 不能这么写吗
//class Father;
//class Son;
class Father;
class Son;


class Father
{
public:

	int money = 1000;

	Father() {};
	~Father() {};

};


//class Son : public Father {
//	// 什么都不写，只继承就行
//};


int main() {

	std::cout << "..in inherit_simple...\n";

	Son son_a;
	std::cout << "..son_a has father's money :: " << son_a.money << "\n";

	return 0;
}

//class Father
//{
//public:
//
//	int money = 1000;
//
//	Father() {};
//	~Father() {};
//
//};
//
//写这就不行 为什么
class Son : public Father {
	// 什么都不写，只继承就行
};