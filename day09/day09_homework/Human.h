#pragma once


#include <iostream>


enum class Gender { MALE, FEMAL };

class Human {
public:

	std::string name;

	virtual void work() = 0;


	//抽象类里面能不能定义构造函数？
	//可以有构造函数。 但是还是不能创建对象。
	//创建对象 ---> 构造函数
	//构造函数 ----> 一定创建对象吗？
	
	// 构造函数是用来初始化数据的，可以给子类用于调用初始化呀。
	// explicit构造函数是用来防止隐式转换的。 
	// 隐式调用 T t1 = 12;
	// 显式调用 T t1(12);
	Human() = default;
	explicit Human(std::string name) : name{ move(name) } {
		std::cout << "..log::Human 有参构造...\n";
	}

};