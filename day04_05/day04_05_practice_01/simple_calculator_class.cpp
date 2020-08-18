/*

定义一个计算器类 calc, 包含有 加减乘除 4个函数，要求在calc.h中声明类 ， 在calc.cpp中实现该类的函数。

*/


#include <iostream>
#include "Calc.h"


int main() {

	std::cout << "..in simple_calculator_class...\n";

	Calc calculator;

	std::cout << "3 + 4 = " << calculator.op_add(3, 4) << "\n";
	std::cout << "3 - 4 = " << calculator.op_sub(3, 4) << "\n";
	std::cout << "3 * 4 = " << calculator.op_mul(3, 4) << "\n";
	std::cout << "3 / 4 = " << calculator.op_div(3, 4) << "\n";

	return 0;
}