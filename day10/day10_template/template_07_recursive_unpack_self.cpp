/*

需求：

可变参数模板函数的参数递归拆包

定义一个同名函数空包，

定义一个可变参数模板函数


我觉得可变构造函数的省略方式很不错啊

*/


#include <iostream>


void get_element() {}


template <typename T, typename ... K>	// 把 ... 看成是一个符号
void get_element(T elem_0, K ... elem_n) {
	std::cout << "..element = " << elem_0 << "\n";
	get_element(elem_n ...);
}


int main() {

	get_element(1, 2, 3, 4, 5);

	return 0;
}


/*

output:

..element = 1
..element = 2
..element = 3
..element = 4
..element = 5

*/