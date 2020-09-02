/*

需求

重写父类同名函数

在子类继承父类之后，可以堆父类函数增强扩展。

可以在子类定义与父类相同的函数，并在这个函数体中使用 父类::父类函数()方法调用
父类的函数

定义一个洗衣机，函数 wash

定义一个智能洗衣机，函数 wash

*/


#include <iostream>


class Wash_Machine {
public:
	void wash() {
		std::cout << "..洗衣机洗衣服...\n";
	}
};


class Smart_Wash_Machine : Wash_Machine {
public:
	void wash() {
		
		std::cout << "..智能洗衣机设定洗衣模式...\n";
		
		Wash_Machine::wash();	// 调用父类的函数
	}
};

int main() {

	std::cout << "..in inherit_father_method_rewritten\n";


	Smart_Wash_Machine swm;
	swm.wash();

	return 0;
}



/*

..in inherit_father_method_rewritten
..智能洗衣机设定洗衣模式...
..洗衣机洗衣服...

*/