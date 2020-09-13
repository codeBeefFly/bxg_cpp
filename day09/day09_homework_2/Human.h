#pragma once


#include <iostream>


// 限定范围的枚举
enum class Gender
{
	MALE,
	FEMAL,
};


class Human {
public:


	std::string name;
	virtual void work() = 0;	// 使类成为抽象类，子类需定义，不然也是抽象类，抽象类没有对象


	Human() = default;

	// 显示初始化数据 explicit
	explicit Human(std::string name) : name{ move(name) } {	// 使用右值初始化
		std::cout << "..log::Human 有参构造函数...\n";
	}

};
