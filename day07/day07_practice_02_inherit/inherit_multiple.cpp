/*

需求：

多重继承 + 构造


解决多重继承的二义性问题
继承的成员同名而产生的二义性(ambiguous)问题。

解决办法，使用范围修饰符 ::



*/

#include <iostream>


class Mother {
public:
	std::string name;

	Mother(std::string name) : name{ name } {
		std::cout << "..mother 构造函数...\n";
	};
	~Mother() {
		std::cout << "..mother 析构函数...\n";
	};

	void say() {
		std::cout << "..mother " << this->name << " do housework...\n";
	}
};



class Father {
public:
	std::string name;

	Father(std::string name) : name{ name } {
		std::cout << "..father 构造函数...\n";
	};
	~Father() {
		std::cout << "..father 析构函数...\n";
	};

	void say() {
		std::cout << "..Father " << this->name << " earn money...\n";
	}
};


class Son : public Father, public Mother {	// 同时继承了 同名的 name 这个变量

public:
	
	std::string name;

	// 子类的有参构造函数，继承了两个父类的成员，所以可以通过有参构造初始化这两个成员
	// 注意这里，是如何通过有参构造的初始化列表方式初始化
	// 当前类，父类的成员
	// 初始化父类成员通过 父类的构造函数的方式
	Son(std::string name, std::string f_name, std::string m_name) : name{ name }, Father(f_name), Mother(m_name) {
		std::cout << "..Child 构造函数...\n";
	}
	~Son() {
		std::cout << "..Chile 析构函数...\n";
	}

	void say() {
		Father::say();
		Mother::say();
		
		std::cout << "..Child's Father " << Father::name << ", Mother " << Mother::name << ", and Child " << this->name << " live together.\n";
	}

};


int main() {

	std::cout << "..in inherit_multiple...\n";

	Son s("jacob", "Lee", "Jin");
	s.say();

	return 0;

}



/*

..in inherit_multiple...
..father 构造函数...
..mother 构造函数...
..Child 构造函数...
..Father Lee earn money...
..mother Jin do housework...
..Child's Father Lee, Mother Jin, and Child jacob live together.
..Chile 析构函数...
..mother 析构函数...
..father 析构函数...

*/