/*

需求：

调用重载运算符()

*/


#include <iostream>
#include <math.h>


class Calculator
{
public:

	int oprand_a, oprand_b;

	Calculator();
	
	Calculator(int oprand_a, int oprand_b);
	
	~Calculator();

	int operator()(int&& op_a, int&& op_b);

};

Calculator::Calculator() : Calculator(0, 0)
{
	std::cout << "..log::无参构造...\n";	 
}


Calculator::Calculator(int oprand_a, int oprand_b) 
	: oprand_a{ oprand_a }
	, oprand_b{ oprand_b }{
	std::cout << "..log::有参构造...\n";
}


Calculator::~Calculator()
{
	std::cout << "..log::析构函数...\n";
}


int Calculator::operator()(int&& op_a, int&& op_b) {		// 重载
	return op_a + op_b;
}


int main() {

	std::cout << "..in operator_overload_bracket...\n";

	Calculator cal;
	std::cout << "cal(3, 5) = " << cal(3, 5) << "\n";

	std::plus<int> p;
	std::cout << "plus(3, 5) = " << p(3, 5) << "\n";

	return 0;
}