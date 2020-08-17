#include "stu.h"

/*

void initStudent(
	std::string&& name,							// 需求：右值引用
	std::string&& id,							// 需求：右值引用
	std::vector<int>& score_vector,				// 需求：左值引用
	std::vector<student*>* student_vector
) 

*/

typedef void(*initStudent_ptr)(
	std::string&& name,							// 需求：右值引用
	std::string&& id,							// 需求：右值引用
	std::vector<int>& score_vector,				// 需求：左值引用
	std::vector<student*>* student_vector
	);


//void initScore(		// 函数指针作为参数形式2，使用 typedef
//	std::vector<student*>* student_vector,
//	initStudent_ptr initStudent_fun
//) {

void initScore(	// 函数指针作为参数形式1
	std::vector<student*>* student_vector,
	void (*initStudent_ptr)(
			std::string&& name,							// 需求：右值引用
			std::string&& id,							// 需求：右值引用
			std::vector<int>& score_vector,				// 需求：左值引用
			std::vector<student*>* student_vector
		)

) {
	
	for (int i = 0; i < 3; i++) {	// 循环3次创建3个学生对象，学生对象要放到容器
		
		std::cout << "..输入第[" << i + 1 << "]个学生的信息...\n";
		
		std::cout << "...学生姓名::\t";
		std::string name;
		std::cin >> name;

		std::cout << "...学生学号::\t";
		std::string id;
		std::cin >> id;

		std::cout << "...学生成绩::\n";
		std::vector<int> score_vector;
		for (int j = 0; j < 6; j++) {
			std::cout << "....第[" << j + 1 << "]科成绩::\t";
			int score;
			std::cin >> score;
			score_vector.push_back(score);
		}

		// 创建一个学生对象，并放入容器，调用 iniStudent 函数 
		// 方法1：使用typedef 重新给函数指针命名
		//initStudent_fun(move(name), move(id), score_vector, student_vector);
		// 方法2：直接使用函数名
		initStudent_ptr(move(name), move(id), score_vector, student_vector);
		

	}
}

void updateScore(std::vector<student*>* student_vector, void (*update_ptr)(int*)) {
	for (student* student : (*student_vector)) {
		for (int& score : (*student).score_vector) {	// 使用引用就可以修改vector中的元素值
			if (score < 60) {
				update_ptr(&score);
			}
		}
	}
}

void printScore(std::vector<student*>* student_vector, void (*print_ptr)(std::vector<student*>*)) {
	print_ptr(student_vector);
}