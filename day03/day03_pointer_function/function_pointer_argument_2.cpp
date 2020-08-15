/*

目的：
使用函数指针，传递 printScore()函数

需求
1. 数据 vector<int>
2. 客户端有相同功能的打印函数 printScore_0(vector<int>), printScore_1(vector<int>);
3. 程序员提供的打印接口 print_api(vector<int>, (*print_ptr)(vector<int>))
4. 创建一个入口函数
5. 写成 prototype + 入口函数 + 函数定义形式


形参：在函数定义中出现
实参：在函数调用中出现

*/


#include<iostream>
#include<vector>


// 客户端打印函数
void printScore_0(std::vector<int>);
void printScore_1(std::vector<int>);
void printScore_2(std::vector<int>);


// 程序提供的打印api
void print_api(std::vector<int>, void (*print_ptr)(std::vector<int>));


int main() {
	
	std::vector<int> scores{ 1, 2, 3, 4, 5, 6 };

	// 客户0使用他们的方法使用程序api打印
	print_api(scores, printScore_0);

	// 客户1使用他们的方法使用程序api打印
	print_api(scores, printScore_1);


	// 客户2使用他们的方法使用程序api打印
	print_api(scores, printScore_2);

	return 0;
}


void printScore_0(std::vector<int> score_vector) {
	std::cout << "\n..in printScore_0...\n"
		<< "..scores ::\t";
	for (int score : score_vector) {
		std::cout << score << "\t";
	}
}


void printScore_1(std::vector<int> score_vector) {
	std::cout << "\n..in printScore_1...\n"
		<< "..scores ::\t";
	for (int score : score_vector) {
		std::cout << score << "\t";
	}
}


void printScore_2(std::vector<int> score_vector) {
	std::cout << "\n..in printScore_2...\n"
		<< "..scores ::\t";
	// 使用下标打印
	for (int i = 0; i < score_vector.size(); i++) {
		std::cout << score_vector[i] << "\t";
	}
}


void print_api(std::vector<int> score_vector, void (*print_fun_ptr)(std::vector<int>)) {
	print_fun_ptr(score_vector);
}