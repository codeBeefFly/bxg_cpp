 /*
 
 practice_02: 捕获列表方式

 lambda 完整的表达式（内联匿名函数）

 [](参数类型 参数名)->返回值类型{}				// 返回的是函数指针，需要函数指针变量来接收（左值）

 []: 捕获列表
 {}: 函数体
 
 */


#include <iostream>

// 一般函数形式对比 lambda 函数
int add(int a, int b) {
	return a + b;
}


/*

lambda 函数的三种调用方式

*/
int main() {

	// auto 变量接收 lambda 返回值
	auto add = [](int a, int b)->int {return a + b; };		// 或者 auto result = [](int a, int b){return a + b;};
	int result = add(3, 4);
	std::cout << "result = " << result << "\n";

	// 函数指针接收
	int (*add_2)(int, int) = [](int a, int b) { return a + b; };
	int result2 = add_2(3, 4);
	std::cout << "result2 = " << result2 << "\n";


	// 直接lambda函数后小括号赋值返回结果
	int result3 = [](int a, int b) { return a + b; }(3, 4);
	std::cout << "result3 = " << result3 << "\n";

	// 尝试用 auto
	auto result4 = [](int a, int b) { return a + b; }(3, 4);
	std::cout << "result4 = " << result4 << "\n";

	return 0;

}