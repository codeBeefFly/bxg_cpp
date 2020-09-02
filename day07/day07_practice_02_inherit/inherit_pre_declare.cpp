/*

一般来说，类和 变量是一样的，必须先声明然后再使用，
如果在某个类里面定义类另一个类的对象变量，
那么必须在前面做前置声明，才能编译通过。


目前还不清楚这个有什么用

先抄一遍

*/



#include <iostream>

class Father;	// 前置声明父类


class Son {

public:
	Father* f_1;
	Father& f_2;

	Son(Father* f_1, Father& f_2) : f_1(f_1), f_2(f_2) { // 这就是一般的列表初始化

	}
};


class Father {

};


int main() {

	std::cout << "..inherit_pre_declare...\n";

	Father f1;
	Father f2;

	Son s(&f1, f2);

	return 0;
}