/*

����һ���������� calc, ������ �Ӽ��˳� 4��������Ҫ����calc.h�������� �� ��calc.cpp��ʵ�ָ���ĺ�����

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