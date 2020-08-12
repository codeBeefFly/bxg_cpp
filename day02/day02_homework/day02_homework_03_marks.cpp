/*
需求

3. 使用二维vector 用于保存张三、李四、王五，三人的6个学科的成
绩，
a. 定义一个二维vector，名叫：score_vector，用来存储三个
学生的6个学科成绩
b. 定义一个initScore（vector<vector>）函数负责从键盘录入
成绩
c. 定义一个函数updateScore（vector<vector>） ，用于更新
分数，把每个人的不及格的成绩全部修改成99分，
d. 定义一个函数 printScore （vector<vector>），遍历打印三
个人的每个学科成绩。
e. 要求使用函数原型、分离式写法（头文件和源文件） 、函
数传递引用，基于范围for循环。
f. 禁止定义全局静态vector ，要求2 ，3 ，4 步骤的函数要携
带参数，把二维vector传递进去。
g. 超纲： 应该要考虑引用，否则更新的操作无法实现。具体
使用可看上面的引用。

*/

#include <iostream>
#include "basic_operation.h"


int main() {
	std::cout << "..day02_homework_03_marks..." << std::endl;

	std::vector<std::vector<int>> score_vector;		// // empty vector of ints

	initScore(score_vector);

	printScore(score_vector);

	updateScore(score_vector);

	printScore(score_vector);

	return 0;
}