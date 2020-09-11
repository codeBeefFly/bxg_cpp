/*

需求：

练习 限定作用域的枚举 class + 非限定作用域枚举

语法：
enum class 枚举名称 { 枚举量1, 枚举量2, ... }



 * 枚举
 *      enum ,
 *      0. 限定作用域  enum class 枚举的名称 { 枚举量1 , 枚举量2 ... }
 *      1. 枚举里面的每一个枚举量都对应着一个数字，这个数字从0 开始。
 *      2. 在限定范围里面的时候，需要手动强转它。
 *      3. 限定范围和不限定范围的写法有什么区别。
 

*/


#include <iostream>


enum class Color	// 限定作用域枚举
{
	RED,
	GREEN,
	YELLO
};


enum Color_Small
{

	S_RED,
	S_GREEN,
	S_YELLO,

};



int main() {

	{
		std::cout << (int)Color::RED << "\n";
		std::cout << (int)Color::GREEN << "\n";
		std::cout << (int)Color::YELLO << "\n";

		// 报错
		//std::cout << Color::RED << "\n";
		//std::cout << Color::GREEN << "\n";
		//std::cout << Color::YELLO << "\n";
	}

	{
		std::cout << S_RED << "\n";
		std::cout << S_GREEN << "\n";
		std::cout << S_YELLO << "\n";
	}


	return 0;
}


/*

output


0
1
2

0
1
2

*/