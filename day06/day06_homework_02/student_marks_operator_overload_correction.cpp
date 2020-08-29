/*

### 2. 综合演练

1. 定义学生类 `stu`，包括
   1. 属性：姓名、学号、学校、分数
   2. 姓名为指针类型，学号为普通字符串、学校为静态成员、分数为` vector<int>`
2. 学生类应该具有 `stu.h` 和` stu.cpp` 两个文件
   1. `stu.h`用于声明属性以及以上三个函数的声明
   2. `stu.cpp` 应该作为这三个函数的具体实现
3. 在 main 函数里面，定义全局变量 `vector<student*> stu_vector`
4. 定义全局函数 `initStu` 初始化学生信息，至少录入3个学生信息
5. 定义全局函数 `updateStu` 更新学生成绩，采用函数指针方式更新
   1. 函数内部应该先询问更新到具体的什么分数，然后使用 `switch` 判断
   2. 进而传递进去对应的函数指针
6. 定义全局函数 `printStu` 用于打印学生信息，要求学生类重载运算符 `<<`，然后使用 `cout << s << endl;`，`s` 为学生对象的方式打印出学生信息。查看笔记
7. 附加选项：定义全局函数 deleteStu 用于删除学生，从键盘录入学生学号，匹配之后，从容器中删除该学生。
8. 释放学生，回收内存。



*/

#include <iostream>
#include "Student.h"

void initStu(std::vector<Student*>& student_vector);
//void updateStu(std::vector<Student*>& student_vector, int target_score, void (*fun)(std::vector<Student*>& student_vector, int target_score));
void updateStu(std::vector<Student*>& student_vector);
void printStu_normal(std::vector<Student*> student_vector);
void printStu_overload(std::vector<Student*> student_vector);
void deleteStu(std::vector<Student*>& student_vector);

std::ostream& operator<<(std::ostream& out, Student& stu);

void update_to_target(std::vector<Student*>& student_vector, int target_score);


int main() {

	std::cout << "..in student_marks_operation_overload_correction...\n";

	std::vector<Student*> student_vector;

	// 初始化学生
	initStu(student_vector);

	// 更新学生成绩
	//int target_score{ 0 };
	//updateStu(student_vector, target_score, update_to_target);
	updateStu(student_vector);

	// 打印学生
	printStu_normal(student_vector);

	// 删除学生
	deleteStu(student_vector);


	return 0;

}


void initStu(std::vector<Student*>& student_vector) {
	std::cout << "\n******************************** 初始化学生类 ********************************\n";
	
	std::cout << "..输入学生个数::\t";
	int number{ 0 };
	std::cin >> number;
	if (number == 0) {
		std::cout << "..学生个数为 0...\n";
	}
	for (int i = 0; i < number; i++) {
		std::cout << "..输入第[" << i + 1 << "]个学生姓名，id::\t";
		std::string tmp_name, tmp_id;
		std::cin >> tmp_name >> tmp_id;

		std::vector<int> score_vector{};
		for (int j = 0; j < 6; j++) {
			std::cout << "..输入第[" << j + 1 << "]门课的成绩::\t";
			int tmp_score{ 0 };
			std::cin >> tmp_score;
			score_vector.push_back(tmp_score);
		}

		Student* stu = new Student(tmp_name, tmp_id, score_vector);
		student_vector.push_back(stu);
		
	}
}


//void updateStu(std::vector<Student*>& student_vector, int target_score, 
//	void (*fun)(std::vector<Student*>& student_vector, int target_score)) {
//	std::cout << "\n******************************** 更新学生成绩 ********************************\n";
//	
//	fun(student_vector, target_score);
//}

void updateStu(std::vector<Student*>& student_vector) {
	std::cout << "\n******************************** 更新学生成绩 ********************************\n";

	std::cout << "..输入需要更新到的成绩::\t";
	int target_score;
	std::cin >> target_score;

	update_to_target(student_vector, target_score);
}


void printStu_normal(std::vector<Student*> student_vector) {
	std::cout << "\n******************************** 打印学生成绩 ********************************\n";

	for (Student* stu : student_vector) {
		std::cout << "..学生姓名::\t" << stu->name << ", id::\t" << stu->id << "\n";
		std::cout << "..学生分数::\t";
		for (int score : stu->score_vector) {
			std::cout << score << "\t";
		}
		std::cout << "\n";
	}
}


void printStu_overload(std::vector<Student*> student_vector) {
	std::cout << "\n*************************** 打印学生成绩(overload) ***************************\n";

	for (Student* stu : student_vector) {
		std::cout << stu;
	}
}


std::ostream& operator<<(std::ostream& out, Student& stu) {
	out << "..学生姓名::\t" << stu.name << ", id::\t" << stu.id << "\n";
	out << "..学生分数::\t";
	for (int score : stu.score_vector) {
		out << score << "\t";
	}
	out << "\n";

	return out;
}


//void deleteStu(std::vector<Student*>& student_vector) {
//	std::cout << "******************************** 删除指定学生 ********************************";
//
//	std::cout << "..输入需要删除的学生id::\t";
//	std::string target_id;
//	std::cin >> target_id;
//
//	for (Student* stu : student_vector) {
//		if (stu->id == target_id) {
//			std::cout << "..学生 [" << stu->name << "] 删除..\n";
//			delete stu;
//		}
//	}


void deleteStu(std::vector<Student*>& student_vector) {
	std::cout << "\n******************************** 删除指定学生 ********************************\n";
	
	std::cout << "..输入需要删除的学生id::\t";
	std::string target_id;
	std::cin >> target_id;

	for (auto ptr = student_vector.begin(); ptr < student_vector.end(); ptr++) {
		if ((*ptr)->id == target_id) {			// ptr 是 student*
			delete* ptr;
			//student_vector.erase(*ptr);
		}
	}
}

void update_to_target(std::vector<Student*>& student_vector, int target_score) {
	for (Student* stu : student_vector) {
		for (int& score : stu->score_vector) {
			if (score < 60) {
				score = target_score;
			}
		}
	}
}