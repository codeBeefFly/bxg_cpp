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


int main() {
	
	std::cout << "..in homework_student_class_01...\n";

	//1. 定义容器
	std::vector<Student*> stu_vector;

	Student* tmp_stu = nullptr;

	//2. 键盘获取学生的数据，只用获取两个学生成绩，另一个学生成绩使用拷贝
	// 使用两个for loop，外层接收姓名+年龄，内层接收分数
	for (int i = 0; i < 2; i++) {
		std::cout << "..输入学生[" << i + 1 << "]..\n"
			<<"...姓名::\t";
		std::string tmp_name;
		std::cin >> tmp_name;

		std::vector<int> score_vector;
		for (int j = 0; j < 6; j++) {
			std::cout << "...学科[" << j + 1 << "]成绩::\t";
			int tmp_score;
			std::cin >> tmp_score;
			score_vector.push_back(tmp_score);
		}

		////创建学生对象，一般的方式
		//Student stu;
		//*stu.name = tmp_name;
		//stu.score_vector = score_vector;

		////创建学生对象，使用有参构造的方式
		//Student tmp_stu(&tmp_name, score_vector);
		////Student tmp_stu = new Student(&tmp_name, score_vector);
		//
		////测试
		//std::cout << &tmp_stu << "\n";
		//std::cout << *tmp_stu.name << "\n";		// 没有值
		//for (int score : tmp_stu.score_vector) {
		//	std::cout << "score::\t" << score << "\t";
		//}

		//Student* tmp_stu = new Student(&tmp_name, score_vector);
		tmp_stu = new Student(&tmp_name, score_vector);

		//Student stu = tmp_stu;

		////将学生对象推进向量中
		//std::cout << &stu << "\n";
		//stu_vector.push_back(&stu);

		//将学生对象推进向量中
		//std::cout << &tmp_stu << "\n";
		//stu_vector.push_back(&tmp_stu);
		std::cout << tmp_stu << ", " << *(*tmp_stu).name << "\n";
		stu_vector.push_back(tmp_stu);
	}

	// 问题出在这，没有数据，不知道什么情况
	std::cout << *(*tmp_stu).name << "\n";

	// 使用类中 showInfo 方式
	for (Student* stu : stu_vector) {
		std::cout << "..log..打印学生成绩...\n";

		std::cout << "..学生姓名::\t" << *(*stu).name << "\n";
		(*stu).showInfo();
	}

	// 将第三个学生拷贝出来，当前容器中只有两个学生
	//Student* stu_c = stu_vector.back();			//这已经赋值了，名字+成绩向量，不能这样赋值，不仅把第二个学生的地址搞没了（？）
	
	Student stu_c = *(stu_vector.back());			//稍等 

	std::cout << "..输入第三个学生姓名::\t";
	std::string tmp_name;
	std::cin >> tmp_name;
	*stu_c.name = tmp_name;


	// 使用类中 showInfo 方式
	for (Student* stu : stu_vector) {
		std::cout << "..log..打印学生成绩...\n";

		(*stu).showInfo();
	}

	///3. 修改成绩
	//遍历学生对象，修改学生成绩
	for (Student* stu : stu_vector) {
		std::cout << "..log::修改学生成绩...\n";

		(*stu).updateScore(nullptr);
	}

	///4. 打印成绩
	
	/*	传统的方式
	
	//遍历学生对象，打印学生成绩
	for (Student* stu : stu_vector) {
		std::cout << "..log::打印学生成绩...\n";
		
		std::cout << "..学生姓名::\t" << (*stu).name << "\n";
		int score_index{ 0 };
		for (int score : (*stu).score_vector) {
			std::cout << "..分数[" << score_index + 1 << "]::\t" << score << "\n";
			score_index++;
		}
	}
	
	*/

	// 使用类中 showInfo 方式
	for (Student* stu : stu_vector) {
		std::cout << "..log..打印学生成绩...\n";

		(*stu).showInfo();
	}


	return 0;
}
