/*

需求：


我还是感觉 用 递归比较好，什么都不用导

递归拆包要用递归

使用 initializer_list 实现可变参数模板函数，要导 <initializer_list>

initializer_list 拆包要用迭代

*/


#include <iostream>
#include <initializer_list>


// 定义一个打印元素的可变参数模板函数
template <typename T>
void get_elem(std::initializer_list<T> list) {
	for (auto i = list.begin(); i < list.end(); i++) {
		std::cout << *i << "\t";
	}
}


template <typename T>
T sum(std::initializer_list<T> list) {
	T total{};	// 必须要初始化，使用无参初始化
	for (auto i = list.begin(); i < list.end(); i++) {
		total += *i;
	}
	return total;
}



int main() {

	std::cout << "..in template_08_initialzier_list_self...\n";

	get_elem({ 1, 2, 3, 4, 5 });

	std::cout << "\n..total of 1, 2, 3, 4, 5 = " << sum({ 1, 2, 3, 4, 5 }) << "\n";

	return 0;
}


/*

output:

..in template_08_initialzier_list_self...
1       2       3       4       5
..total of 1, 2, 3, 4, 5 = 15


*/