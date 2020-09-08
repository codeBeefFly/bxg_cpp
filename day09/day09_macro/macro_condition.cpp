/*

需求

在函数体中检查宏是否存在

*/

#define USE_MATH_DEFINES
#define PI 3.14

#include <iostream>
#include <cmath>



int main() {

	std::cout << "..in macro_condition...\n";


	std::cout << "..PI = " << PI << "\n";

#ifdef PI
	std::cout << "..PI defined...\n";
#endif // PI

#ifndef PI_2
#define PI_2 3.1416
	std::cout << "..PI2 not defined...\n";
	std::cout << "..after define PI2 = " << PI_2 << "\n";
#endif // !PI_2



	return 0;
}


/*

..in macro_condition...
..PI = 3.14
..PI defined...
..PI2 not defined...

*/