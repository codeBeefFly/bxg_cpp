/*

需求：

调用父类构造器


子类只能使用初始化列表的方式来访问父类构造

+ 初始化对象成员

*/


#include <iostream>


//class A {
//public:
//	A() {}
//	A(int number) : number{ number } {}
//	~A() {}
//
//	int number;
//};

class Father
{
public:
	Father();
	Father(std::string name) : name { name } {
		std::cout << "..父类有参构造...\n";
	}
	~Father();

	std::string name;
	//A a;
};

Father::Father()
{
	std::cout << "..父类无参构造...\n";
}

Father::~Father()
{
	std::cout << "..父类析构函数...\n";
}


class Son : public Father
{
public:
	Son();
	Son(std::string name) : Father(name) {
		std::cout << "..子类有参构造函数...\n";
	}
	~Son();

	//std::string name;		// 继承父类的成员，不用再写了
};

Son :: Son()
{
	std::cout << "..子类无参构造...\n";
}

Son :: ~Son()
{
	std::cout << "..子类析构函数...\n";
}


int main() {

	std::cout << "..in inherit_invoke_father_constructor...\n";

	Son s("jacob");
	
	std::cout << "..学生姓名::\t" << s.name << "\n";

	return 0;
}


/*

output

..in inherit_invoke_father_constructor...
..父类有参构造...
..子类有参构造函数...
..学生姓名::    jacob
..子类析构函数...
..父类析构函数...

*/