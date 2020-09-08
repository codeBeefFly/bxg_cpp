/*

需求：

模板编程

使用 initializer_list

函数返回类型 函数名称(initializer_list<元素类型> list_名称)

使用迭代器方式 list_名称.begin(), list_名称.end(), list指针++

抄一遍

定义两个加法函数，可以获取不定长参数

第二个加法函数的元素类型是模板，即，将不定长参数函数模板化

*/


#include <iostream>
#include <initializer_list>


int add(std::initializer_list<int> list) {

	// 测试，打印列表数据
	//for (auto ptr = list.begin(); ptr < list.end(); ptr++) {
	//	std::cout << *ptr << "\t";
	//}
	// 1       3       5       7

	int sum{ 0 };
	for (auto ptr = list.begin(); ptr < list.end(); ptr++) {
		sum += *ptr;
	}

	return sum;
}



int main() {

	std::cout << "..in template_04...\n";

	std::cout << add({ 1, 3, 5, 7 });		//  必须放在 {}
	//std::cout << add( 1, 3, 5, 7 );		// 报错


	return 0;
}


/*

output

16


*/