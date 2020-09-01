/*

需求：
学习 lambda 的捕获列表

原因，cpp 不允许在函数内部定义函数

lambda在主体函数中捕获两个局部变量，通过 = 值传递或 & 引用传递的方式

*/


#include <iostream>



int main() {

	std::cout << "..day07_lambda_capture_list...\n";

	int number_1{ 3 }, number_2{ 4 };
	std::cout << "..&number_1 :: " << &number_1 << "\n"
		<< "..&number_2 :: " << &number_2 << "\n";

	auto result_add = [=] {
		std::cout << "..&number_1 :: " << &number_1 << "\n"
			<< "..&number_2 :: " << &number_2 << "\n";
		return number_1 + number_2;
	};
	std::cout << "..result_add = " << result_add() << "\n";

	auto result_sub = [&] {
		std::cout << "..&number_1 :: " << &number_1 << "\n"
			<< "..&number_2 :: " << &number_2 << "\n";
		return number_1 - number_2;
	};
	std::cout << "..result_sub = " << result_sub() << "\n";



	return 0;
}



/*

output:


..day07_lambda_capture_list...
..&number_1 :: 000000A9894FF884
..&number_2 :: 000000A9894FF8A4
..&number_1 :: 000000A9894FF8C8
..&number_2 :: 000000A9894FF8CC
..result_add = 7
..&number_1 :: 000000A9894FF884
..&number_2 :: 000000A9894FF8A4
..result_sub = -1

*/