/*

需求：
使用 function 模板 调用函数
1. 全局函数
2. lambda 函数

*/


#include <functional>
#include <iostream>



int add(int a, int b) {
	return a + b;
}


int main() {

	std::cout << "..in day11_function_object_01_global_lambda...\n";

	// function 模板 调用全局函数
	std::function<int(int, int)> f = add;
	std::cout << "...add(3, 4) = " << f(3, 4) << "\n";


	// function 模板 调用lambda 函数
	std::function<int(int, int)> f_lbd = [](int a, int b) { return a + b; };
	std::cout << "...add(3, 4)_lbd = " << f_lbd(3, 4) << "\n";



	return 0;
}



/*

output

..in day11_function_object_01_global_lambda...
...add(3, 4) = 7
...add(3, 4)_lbd = 7


*/