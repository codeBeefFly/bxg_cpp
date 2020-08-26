/*

需求：

1. 定义学生类 Student，包括
	1. 属性：姓名、学号、学校、分数
	2. 姓名为指针类型，学号为普通字符串，学校为静态成员，分数vector<int>

2. 学生类应该具有 stu.h 和 stu.cpp 两个文件
	1. stu.h 用于声明属性以及函数
	2. stu.cpp 应该作为这三个函数的具体实现  构造 析构 拷贝

3. 在 main 函数里面，定义局部变量 vector<stu *> stu_vector

4. 定义全局函数 initStu 初始化学生信息，至少需要录入3个学生信息

5. 定义全局函数 updateStu 更新学生成绩，采用函数指针的方式更新
	函数内部线询问具体更新到什么分数，然后使用 switch 判断
	进而传递进去对应的函数指针

6. 定义全局函数 printStu 用于打印学生信息，要求学生类重载运算符 <<
	然后使用 cout << s << endl, s为学生对象的方式打印出学生信息。查看笔记。

7. 附加选项
	定义全局函数 deleteStu 用于删除学生，重键盘录入学生学号，
	匹配之后，从容器中删除该学生。

*/

#include <iostream>
#include "Student.h"


void initStu(std::vector<Student*>& student_vector);
void updateStu(std::vector<Student*>& student_vector, void (*update_score)(int& score));	// 函数指针的方式更新
void printStu_normal(std::vector<Student*> student_vector);
void printStu_op_overload(std::vector<Student*> student_vector);
void deleteStu(std::vector<Student*>& student_vector);

void update2_60(int& score);
void update2_70(int& score);
void update2_80(int& score);

std::ostream& operator<<(std::ostream& out, Student& stu);


int main() {

	std::cout << "..in student_marks_operator_overload...\n";

	std::vector<Student*> stu_vector;

	// 初始化至少三个学生
	initStu(stu_vector);

	// 更新学生成绩
	updateStu(stu_vector, update2_60);

	// 打印学生成绩
	printStu_normal(stu_vector);
	printStu_op_overload(stu_vector);

	// 删除学生
	deleteStu(stu_vector);

	return 0;
}


void initStu(std::vector<Student*>& student_vector) {
	std::cout << "\n************ 初始化学生 ************\n";

	for (int i = 0; i < 3; i++) {
		std::cout << "..输入学生[" << i + 1 << "]姓名::\t";
		std::string tmp_name;
		std::cin >> tmp_name;

		std::cout << "..输入学生[" << i + 1 << "]id::\t";
		std::string tmp_id;
		std::cin >> tmp_id;

		std::vector<int> score_vector;
		int tmp_score{ 0 };
		for (int i = 0; i < 6; i++) {
			std::cout << "..输入第[" << i + 1 << "]科成绩::\t";
			std::cin >> tmp_score;
			score_vector.push_back(tmp_score);
		}
		
		Student* stu = new Student(tmp_name, tmp_id, score_vector);
		
		student_vector.push_back(stu);
	}
}


void updateStu(std::vector<Student*>& student_vector, void (*update_score)(int& score)) {
	std::cout << "\n************ 更新学生成绩 ************\n";

	for (Student* student : student_vector) {
		for (int& score : student->score_vector) {
			update2_60(score);
		}
	}
}


void printStu_normal(std::vector<Student*> student_vector) {
	std::cout << "\n************ 打印学生信息(normal) ************\n";
	
	int student_index{ 0 };
	for (Student* student : student_vector) {
		std::cout << "..学生[" << student_index++ << "]...\n"
			<< "...姓名::\t" << *student->name << "\n"
			<< "...id::\t" << student->id << "\n";

		//int score_index{ 0 };
		std::cout << "..分数::\t";
		for (int score : student->score_vector) {
			//std::cout << "...学科[" << score_index++	 << "]分数::\t" << score << "\n";
			std::cout << score << "\t";
		}
		std::cout << "\n";
	}
}


void printStu_op_overload(std::vector<Student*> student_vector) {
	std::cout << "\n************ 打印学生信息(op_overload) ************\n";

	int student_index{ 0 };
	for (Student* student : student_vector) {
		std::cout << "..学生[" << student_index++ << "]信息如下...\n";
		std::cout << *student << "\n";
	}
}


void deleteStu(std::vector<Student*>& student_vector) {
	std::cout << "\n************ 删除学生对象 ************\n";

	for (Student* student : student_vector) {
		delete student;
	}
}



void update2_60(int& score) {
	if (score < 60) {
		score = 60;
	}
}

void update2_70(int& score) {
	if (score < 70) {
		score = 70;
	}
}

void update2_80(int& score) {
	if (score < 80) {
		score = 80;
	}
}


std::ostream& operator<<(std::ostream& out, Student& stu) {
	out << "..学生姓名::\t" << *stu.name << "\n"
		<< "..学生id::\t" << stu.id << "\n"
		<< "..学科分数::\t";
	for (int score : stu.score_vector) {
		out << score << "\t";
	}
	//out << "\n";

	return out;
}

