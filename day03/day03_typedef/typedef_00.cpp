/*
typedef 的作用是自己习惯的名字，来替已有的类型名称。 
语法： `typedef 已知类型名称 自定义名称`


需求：
1. 使用 typedef 定义 int 与 vector<int>
2. 使用单源文件分离式写法
3. 普通的写法

*/


#include<iostream>
#include<vector>


// 使用 typedef 重命名类型
typedef int my_int;
typedef std::vector<int> vector_int;


// prototype
void printScores(vector_int);


// 入口函数
int main() {

	vector_int score_vector{ 1, 2, 3, 4, 5 };

	printScores(score_vector);

	return 0;
}


// 定义 prototype
// 如果写成 printScore .. 
// unresolved external symbol error :: 未解决的外部符号错误
void printScores(vector_int score_vector) {
	std::cout << "..in printScroe...\n..score_list ::\t";
	for (my_int score : score_vector) {
		std::cout << score << "\t";
	}

}