/*

普通方式调用函数

需求：
1. 使用普通方式调用函数
2. 分块式写法，实现加法函数的普通方式调用

*/


#include <iostream>

int add(int a, int b);

int main() {

	std::cout << "..enter a and b for addition ::\t";
	int a, b;
	std::cin >> a >> b;
	std::cout << "..result :: " << a << " + " << b << " = " << add(a, b);

	return 0;
}

int add(int a, int b) {

	return a + b;
}





