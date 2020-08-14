/*

指针方式调用函数

需求：
1. 使用指针方式调用函数
2. 分块式写法，实现加法函数的普通方式调用

*/


// 声明一个普通的add函数
#include <iostream>


int add(int a, int b);


// 入口函数
int main() {

	std::cout << "..enter a and b for addition ::\t";
	int a, b;
	std::cin >> a >> b;


	// 创建一个函数指针 
	// 函数返回类型 (*自定义的指针名称)(函数参数类型1, 函数参数类型2, ...) = 目标函数名称
	int (*add_ptr)(int, int) = add;


	// 普通方式调用函数
	// 对照  
	// int a = 8;
	// int *ptr = &a;
	// 可以看成，函数名称其实就是函数地址
	int result_function_normal_call = add(a, b);
	std::cout << "..function normal call resualt :: " << a << " + " << b << " = " << result_function_normal_call << "\n";

	// 函数指针方式调用函数
	int result_function_pointer_call = add_ptr(a, b);
	std::cout << "..function pointer call resualt :: " << a << " + " << b << " = " << result_function_pointer_call << "\n";




	return 0;
}


// 定义声明的函数
int add(int a, int b) {

	return a + b;

}

