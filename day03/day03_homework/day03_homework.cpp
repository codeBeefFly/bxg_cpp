/*
需求：

1. 定义结构体stu, 包含学生的姓名（字符串）、学号（字符串）、成绩（vector<int>）6个学科

2. 定义一个vector来保存张三、李四、王五三个学生的信息 ，请使用学生的指针类型。。

   1.  vector< stu* > stu_vector;

3. 三个学生采用new的方式创建出来，保存在堆内存中。

4. 定义initScore函数负责录入学生的信息。 姓名 , 学号 ， 6个学科成绩

5. 定义updateScore函数负责更新学生的沉寂。成绩小于60的，更新为60

6. 定义printScore函数打印学生的信息： 姓名、学号、总分、平均分

7. 使用分离式写法： stu.h  , stu.cpp , main.cpp

   1. stu.h 包含 结构体stu的声明， 三个函数的声明
   2. stu.cpp 包含三个函数的具体实心。
   3. main.cpp 作为程序的入口

8. 三个函数传递vector的时候，请使用指针类型传递。

   initScore(vector <int> & score_vector)

   initScore(vector <stu*>  *score_vector)

*/

#include <iostream>
#include "stu.h"


int main() {

	std::cout << "..in day03_homework..." << std::endl;

	std::vector<student*> stu_vector;

	// 初始化成绩
	initScore(stu_vector);

	// 更新成绩
	updateScore(stu_vector);

	// 打印成绩
	printScore(stu_vector);

	return 0;
}