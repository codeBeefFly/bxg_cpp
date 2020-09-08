/*

需求：

宏变量

定义一个宏变量，打印宏变量

*/

#define _USE_MATH_DEFINES
#define PI 3.1415926

#include <iostream>
#include <cmath>




int main() {

	std::cout << "..in macro_variable...\n";

	std::cout << "..pi = " << M_PI << "\n";
	std::cout << "..PI = " << PI << "\n";
	

	return 0;
}


 /*
 
 output


 ..in macro_variable...
..pi = 3.14159
..PI = 3.14159


 */