/*
typedef 的作用是自己习惯的名字，来替已有的类型名称。 
语法： `typedef 已知类型名称 自定义名称`


需求：
1. 使用 typedef 定义 int 与 vector<int>
2. 使用单源文件分离式写法
3. 下面示例代码，使用`typedef` 简化函数指针 , 
实现的功能都是一样的，只是代码简化了些

*/


#include<iostream>
#include<vector>


// 重新定义基本类型
typedef int my_int;
typedef std::vector<int> vector_int;

// 重新定义一个函数指针
// typedef 函数指针 语法
// typedef 函数返回类型 (*重新定义的函数指针名)(函数的参数类型1, 函数的参数类型2, ...);
typedef void (*fun_ptr)(vector_int);

void printScore(vector_int);
void print_api(vector_int, fun_ptr);


int main() {

	vector_int score_vector{ 1, 2, 3, 4, 5 };

	fun_ptr ps_ptr = printScore;

	// 传递函数指针给 print_api
	print_api(score_vector, ps_ptr);

	std::cout << "\n";
	// 传递函数名给 print_api
	print_api(score_vector, printScore);


	return 0;
}


void printScore(vector_int score_vector) {
	std::cout << "..in printScore, score list ::\t";
	for (my_int score : score_vector) {
		std::cout << score << "\t";
	}
}


void print_api(vector_int score_vector, fun_ptr input_fun) {
	input_fun(score_vector);
}



