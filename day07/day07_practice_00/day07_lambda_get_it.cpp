/*

需求：
三种 lambda 函数的接收

lambda 函数完整语法
[]()->return_type{}

1. 第一种接收方式
auto fun = [](type_1 param_1, ...)->return_type{return ...;};

2. 第二种接收方式
type (*fun)(type_1, ...) = [](type_1 param_1, ...)->return_type{return ...;};

3. 第三种接收方式
type result = [](type_1 param_1, ...)->return_type{return ...}(argument_1, ...);


*/


#include <iostream>

int add_normal_fun_call (int&& a, int&& b) {
	return a + b;
}


int main() {

	std::cout << "..in day07_lambda_get_it...\n";

	// 正常调用函数
	std::cout << "..add_normal_fun_call(3, 4) = " << add_normal_fun_call(3, 4) << "\n";

	// 第一种方式
	auto add_auto_1 = [](int a, int b) { return a + b; };
	std::cout << "..add_auto(3, 4) = " << add_auto_1(3, 4) << "\n";

	auto add_auto_2 = [](int&& a, int&& b) { return a + b; };
	std::cout << "..add_auto(3, 4) = " << add_auto_2(3, 4) << "\n";

	// 第二种方式
	int (*add_ptr)(int, int) = [](int a, int b) { return a + b; };
	std::cout << "..add_ptr(3, 4) = " << add_ptr(3, 4) << "\n";

	// 第三种方式
	int result;
	result = [](int a, int b) { return a + b; }(3, 4);	// 有() 返回值，没有() 返回函数指针
	std::cout << "..result = " << result << "\n";

	return 0;
}


/*

output

..in day07_lambda_get_it...
..add_normal_fun_call(3, 4) = -858993460   // 如果是 int&& 就会是这个值，why？，不能使用一个&，因为返回的是右值，所以只能是 int
..add_auto(3, 4) = 7
..add_auto(3, 4) = 7
..add_ptr(3, 4) = 7
..result = 7


*/