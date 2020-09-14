/*

需求：

可以理解为把函数 、函数的实参以及调用函数的对象打包绑定到一起。
然后用一个变量来接收它，这个变量也就是这些个打包好的整体。


1. 使用 bind 绑定全局函数
2. 使用函数对象接收 bind 绑定的函数


函数对象的语法

std::function<函数返回类型(参数类型)> 函数对象 = 全局函数名;


bind 绑定函数语法，使用 

*/



#include <iostream>
#include <functional>


int add(int a, int b) {

	return a + b;

}


int main() {

	std::cout << "..in day11_bind_00_simple...\n";

	// 使用函数对象接收全局函数
	std::function<int(int, int)> f_add = add;
	std::cout << "..f_add(3, 4) = " << f_add(3, 4) << "\n";


	// 使用 bind 绑定全局函数，使用自动推断类型
	auto p_add = std::bind(add, 3, 4);
	std::cout << "..p_add() = " << p_add() << "\n";


	// 使用 函数对象 接收绑定的全局函数
	std::function<int()> f_add_bind = std::bind(add, 3, 4);
	std::cout << "..f_add_bind() = " << f_add_bind() << "\n";


	return 0;

}


/*

output:

..in day11_bind_00_simple...
..f_add(3, 4) = 7
..p_add() = 7
..f_add_bind() = 7


*/