/*

需求：
1. 定义学生类 Student，包含
	1. 属性：姓名（name）指针类型，分数（vector存储）
	2. 函数：putScore() 用于添加分数，接收 int 类型分数。
	3. 函数：updateScore() 用于更新该学生分数，不足60分改为60分
	4. 函数：showInfo() 用于输出学生 姓名，总分，平均分，各科分数

2. 学生类分离式写法 Student.h, Student.cpp
	1. Student.h：声明属性+函数
	2. Student.cpp：实现

3. 在 main() 中，定义局部变量 vector<Student*> stu_vector

4. 创建三个学生，a，b，c，c与b分数一样

5. 采用拷贝构造的方式创建 c，然后再修改该学生的姓名

具体要求：
1. 构造函数定义无参，有一个参数，有两个参数的三种构造类型

2. 采用初始化列表的方式定义构造函数

3. 构造函数要体现出委托机制

4. 学生类中的 name 属性初始值为空指针，注意拷贝问题。

5. stu类中所有函数放在 stu.cpp 中实现，stu.h仅做声明。
	包括
	updateScore(), showInfo(), 构造函数(3个), 析构函数(1个), 拷贝构造函数(1个)

6. 学生类 name 是指针, 在析构函数里面, 要释放这个指针

*/


#include <iostream>
#include "Student.h"


int main(){
	
	std::cout << "..in homework_student_class_01_correction...\n";


	std::vector<Student*> student_vector;

	// 获取学生信息
	std::cout << "\n********输入学生信息********\n";
	for (int i = 0; i < 2; i++) {
		std::cout << "..学生姓名::\t";
		std::string name;
		std::cin >> name;

		std::vector<int> score_vector{};
		for (int j = 0; j < 6; j++) {
			std::cout << "..学科[" << j + 1 << "]成绩::\t";
			int score;
			std::cin >> score;
			score_vector.push_back(score);
		}

		// 在堆中创建学生对象
		Student* stu = new Student(name, score_vector);
		student_vector.push_back(stu);

		//delete stu;		// 对吗？
	}


	// 显示学生信息
	std::cout << "\n********显示学生信息********\n";
	for (Student* stu : student_vector) {
		(*stu).showInfo();
	}

	// 拷贝构造一个学生
	std::cout << "\n********拷贝学生信息********\n";
	Student stu = *student_vector[1];	// 深拷贝，这个stu是在栈里面创建的对象，delete对其没有用
	std::cout << "..学生C姓名::\t";
	std::string tmp_name;
	std::cin >> tmp_name;
	*stu.name = tmp_name;
	student_vector.push_back(&stu);

	// 再拷贝构造一个学生
	//std::cout << "\n********拷贝学生信息********\n";
	//Student* stu = new Student;
	//*stu = *student_vector[1];
	//std::cout << "..学生C姓名::\t";
	//std::string tmp_name;
	//std::cin >> tmp_name;
	//*(*stu).name = tmp_name;
	//student_vector.push_back(stu);


	// 修改学生信息
	std::cout << "\n********修改学生信息********\n";
	for (Student* stu : student_vector) {
		(*stu).updateScore();
	}


	// 显示学生信息
	std::cout << "\n********显示学生信息********\n";
	for (Student* stu : student_vector) {
		(*stu).showInfo();
	}


	// 释放堆空间
	// delete 对 new 创建的对象（堆中的对象），而不是栈中的对象
	std::cout << "\n********释放学生对象********\n";
	for (Student* stu : student_vector) {
		std::cout << "..地址::\t" << stu << "\n";
		delete stu;
	}

	
	return 0;
}