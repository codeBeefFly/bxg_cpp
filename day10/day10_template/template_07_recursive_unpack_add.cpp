/*

需求：

使用可变函数模板实现加法

这个方法很不错啊

*/



#include <iostream>


// 递归函数终止
int add() {
	std::cout << "..递归终止...\n";
	return 0;
}
//void add() {}	// 最后是  elem_0 + add()，所以 add() 必须有返回值

template <typename T, typename ... K>
T add(T elem_0, K ... elem_n) {
	return elem_0 + add(elem_n ...);	// 最后是  elem_0 + add()，所以 add() 必须有返回值
}


int main() {

	std::cout << "..in template_07_recursive_unpack_add...\n";

	std::cout << "..sum of 1, 2, 3, 4, 5 = " << add(1, 2, 3, 4, 5) << "\n";

	return 0;
}


/*

output

..in template_07_recursive_unpack_add...
..递归终止...
..sum of 1, 2, 3, 4, 5 = 15

*/