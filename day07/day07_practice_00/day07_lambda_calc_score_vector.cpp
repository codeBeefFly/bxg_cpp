/*

需求：

lambda 函数接收 vector<int> 变量

*/


#include <iostream>
#include <vector>


int calculte_score_vector(std::vector<int> score_vector);


int main() {

	std::cout << "..in day07_lambda_calc_score_vector...\n";


	std::vector<int> score_vector{ 1, 2, 3, 4, 5, 6 };
	std::cout << "..calculate_score_vector(score_vector) :: " << calculte_score_vector(score_vector) << "\n";

	int total = [=] {	// 值传递方式捕获主函数中所有变量
		int total{ 0 };
		for (int score : score_vector) {
			total += score;
		}
		return total;
	}();				// 没有() 返回函数指针，有() 返回值
	std::cout << "..lambda calculate_score_vector :: " << total << "\n";

	return 0;
}


int calculte_score_vector(std::vector<int> score_vector) {

	int total{ 0 };

	for (int score : score_vector) {

		total += score;
	}

	return total;
}
