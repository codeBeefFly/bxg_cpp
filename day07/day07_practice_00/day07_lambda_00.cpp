 /*
 
 lambda 完整的表达式（内联匿名函数）

 [](参数类型 参数名)->返回值类型{}

 []: 捕获列表
 {}: 函数体
 
 */


#include <iostream>

// 一般函数形式对比 lambda 函数
int add(int a, int b) {
	return a + b;
}


/*

lambda 函数的四种写法

*/
int main() {

	std::cout << "..in day07_lambda_practice_00...\n";

	//第一种，完整写法
	[](int a, int b)->int {return a + b; };

	//第二种，自动推断返回值类型，省略 "->返回类型"
	[](int a, int b) {return a + b; };

	//第三种，没有参数
	[]() {std::cout << "hello ya" << std::endl; };

	//第四种，既然没有参数，就省略 ()
	[] {std::cout << "hello ya" << std::endl; };



	return 0;

}