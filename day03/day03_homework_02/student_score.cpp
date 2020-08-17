/*

三、综合题目
1. 定义结构体stu, 包含学生的姓名（字符串）、学号（字符串）、成绩（vector<int>）6个学科

2. 定义一个vector来保存张三、李四、王五三个学生的信息 ，请使用学生的指针类型。
	这个vector也是一个指针类型，并且它应该由函数createContainer 来创建出来。
   1.  vector< stu* > *stu_vector;

3. 定义一个全局函数(直接在main.cpp中定义)createContainer，用于创建存放学生的vector容器
	1.该函数没有返回值，采用二级指针的方式创建vector的指针。


4. 初始化成绩：
	1. 定义initScore负责录入学生的信息。 姓名 , 学号 ， 6个学科成绩
	2. 但是initScore不作为具体的赋值工作，而是仅仅做键盘的录入功能，
		在该函数获取键盘数据完毕之后，调用initStu完成学生初始化工作。
	3. 定义一个函数initStu,专门用于学生数据的初始化工作。接收参数如下：
		void initStu(姓名， 学号 ， 6个学科成绩的vector , stu_vector);
		其中：姓你类型。
		例如：
			void  initStu(
				string&& name ,
				string&& no ,
				vector<int>& score_vector ,
				vector<stu*> *stu_vector
			);
	4. 这里要考虑左值变右值的问题，因为接收键盘录入的时候用左值来接收，但是初始化学生的函数
		接受的是右值，所以此处需要使用到move函数。详情看视频（22_作业-左值变右值）。
5. 更新成绩：
	1. 定义三个main.cpp中定义全局函数updateToSeventy 、updateToEighty 、updateToNinety ，
		对应的是更新成绩为70,80,90
	2. 在执行调用updateScore函数之前，应该先询问要修改成什么成绩分数，选项为70,80,90.
	3. 根据对应的分数，来调用updateScore函数，并且传入上面更新具体分数的函数指针

6. 打印成绩：
	1. 定义两种打印函数 基于范围的for循环方式：printForRange  ，使用和for i 的方式：printForI.
	2. 在执行printScore , 应该先询问用户，要使用何种方式打印(1: 基于范围for方式， 2: 使用forI方式)
	3. 根据对应的选择，来调用printScore分数，并且传入上面打印方式的函数指针。


7. 使用分离式写法： stu.h  , stu.cpp , main.cpp
   1. stu.h 包含 结构体stu的声明， 三个函数的声明
   2. stu.cpp 包含三个函数的具体实心。
   3. main.cpp 作为程序的入口

8. 最后不要忘记了回收三个学生的内存空间。


注意：全局函数是指在 main.cpp 中定义的函数

*/


#include <iostream>
#include <vector>
#include "stu.h"
 

void createContainer(std::vector<student*>** student_vector_ptr);
void initStudent(
	std::string&& name,							// 需求：右值引用
	std::string&& id,							// 需求：右值引用
	std::vector<int>& score_vector,				// 需求：左值引用
	std::vector<student*>* student_vector	
);

// 定义更新相关的函数
void updateToSeventy();
void updateToEighty();
void updateToNinety();

// 定义打印相关的函数
void printForIndex(std::vector<student*>* student_vector);
void printForRange(std::vector<student*>* student_vector);


// 程序入口
int main() {

	// 1. 定义一个容器，用来装三个学生，使用指针
	std::vector<student*>* student_vector = nullptr;

	// 2. 创建容器, 参数为二级指针, 传一个指针的地址
	createContainer(&student_vector);

	// 3. 初始化成绩
	initScore(student_vector, initStudent);	// 函数名称=函数的地址				    

	// 4. 更新成绩	 
	//updateScore(student_vector);

	// 5. 打印成绩
	std::cout << "..选择打印方式：1. 基于范围，2. 基于脚标 ::\t";
	int print_choice;
	std::cin >> print_choice;
	
	switch (print_choice)
	{
	case 1:
		printScore(student_vector, printForRange);
		break;
	case 2:
		printScore(student_vector, printForIndex);
		break;
	default:
		std::cout << "..输入错误...\n";
		break;
	}


	 			 
	return 0;
}



void createContainer(std::vector<student*>** student_vector_ptr) {
	*student_vector_ptr = new std::vector<student*>();
}


void initStudent(
	std::string&& name,							// 需求：右值引用
	std::string&& id,							// 需求：右值引用
	std::vector<int>& score_vector,				// 需求：左值引用
	std::vector<student*>* student_vector
) {

	/*
	
	// 第一种不符合要求的写法
	// stu 是局部对象，在栈内存分配空间，函数执行完毕后消除
	student stu;
	stu.name = name;
	stu.id = id;
	stu.score_vector = score_vector;

	(*student_vector).push_back(&stu);	// 传递的是学生对象的地址，函数执行完毕后内存释放

	*/
	
	// 符合要求的写法
	// 使用 new 在堆内存中开辟一个空间，创建一个 student 类型的指针
	// 通过指针解引用得到 student 类型的对象
	student* stu_ptr = new student;		// stu_ptr = student 类型的地址，这个地址在堆内存
	(*stu_ptr).name = name;
	(*stu_ptr).id = id;
	(*stu_ptr).score_vector = score_vector;

	(*student_vector).push_back(stu_ptr);

}


void printForIndex(std::vector<student*>* student_vector) {
	
	std::cout << "..in printForIndex()...\n";
	
	for (int i = 0; i < (*student_vector).size(); i++) {
		std::cout << "..学生[" << i + 1 << "]的信息...\n";
		student* stu_ptr = (*student_vector).at(i);	// student_vector 中学生类型是一个指针
		std::cout << "...学生姓名:: " << (*stu_ptr).name << "\n";
		std::cout << "...学生学号:: " << (*stu_ptr).id << "\n";

		for (int j = 0; j < (*stu_ptr).score_vector.size(); j++) {
			std::cout << "...学科[" << j + 1 << "]成绩:: " << (*stu_ptr).score_vector.at(j) << "\n";
		}
	}
}


void printForRange(std::vector<student*>* student_vector) {
	
	std::cout << "..in printForRange()...\n";
	
	int student_index{ 0 };
	for (student* stu_ptr : (*student_vector)) {
		std::cout << "..学生[" << student_index + 1 << "]的信息...\n";
		student_index++;
		std::cout << "...学生姓名:: " << (*stu_ptr).name << "\n";
		std::cout << "...学生学号:: " << (*stu_ptr).id << "\n";

		int subject_index{ 0 };
		for (int score : (*stu_ptr).score_vector) {
			std::cout << "...学科[" << subject_index + 1 << "]成绩:: " << (*stu_ptr).score_vector.at(subject_index) << "\n";
			subject_index++;
		}

	}
}