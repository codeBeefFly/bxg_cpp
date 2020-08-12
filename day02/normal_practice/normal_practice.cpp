#include<iostream>
#include <vector>

int practice_01();
int practice_02();
int practice_03();

// function overloading, 这样好像不行, 参数只是引用或值传递不能实现函数重载
std::vector<std::vector<int>> change_score_value(std::vector<std::vector<int>> student_mark_vector);
int change_score_reference(std::vector<std::vector<int>>& student_mark_vector);

int main(){

	//practice_01();		// not finished
	//practice_02();		
	practice_03();		

	return 0;
}


int practice_01() {

	std::cout << "..in day02 practice_01...\n";

	{
		/// 需求
		///给定一串字符串，判定里面有多少个数字，多少个字母。
		///并且把最后那个字母a 修改为大写字母A 
		///修改用的函数是：replace（修改起始索引位置，修改的横跨长度，修改成什 么字符）; 
		///判断是否是字母和数字使用的是 isalpha() 和 isdigit(), 需要引入 #include<ctype.h>
	}

	std::string target_string = "aabb23cccddee12cca";

	// 需求1：计算数字字母个数，isalpha() isdigit() 使用c++ 风格
	int digit_cout { 0 }, alpha_count{ 0 };
	for (char s : target_string) {
		if (isalpha(s))
			alpha_count++;
		else if (isdigit(s))
			digit_cout++;
	}
	std::cout << "..target_string contain " << digit_cout << " number of digits, "
		<< alpha_count << " number of alphabets." << std::endl;

	std::cout << "..here ::" << target_string.length() << target_string.at(17)
	<< target_string.at(target_string.length() - 1)
		<< toupper(target_string.at(target_string.length()-1)) << toupper('a');

	// 需求2：改写最后字母 replace (未完成)
	std::cout << "..target_string before modification :: " << target_string << "\n";
	//int pos = strlen(target_string) - 1;	// strlen 是 C 的 stl
	//target_string.replace(target_string.length() - 1, 1, toupper(target_string.at(target_string.length() - 1)));


	return 0;
}


int practice_02() {

	std::cout << "..in day02 practice_02...\n";

	{
		/// 需求
		///使用二维vector记录三个学生的6门学科成绩，并且计算每个学生的总分，平均分。
	}

	// get info
	std::vector<std::vector<int>> student_vector;
	for (int i = 0; i < 3; i++) {
		std::cout << "..for student_" << i << std::endl;
		std::vector<int> student_mark_vector;
		for (int j = 0; j < 6; j++) {
			std::cout << "..enter subject_" << j << " mark :: ";
			int tmp_mark;
			std::cin >> tmp_mark;
			student_mark_vector.push_back(tmp_mark);
		}
		student_vector.push_back(student_mark_vector);
	}

	// show info, 使用 基于范围for的遍历	需要的是元素的类型
	// 对于 std::vector<std::vector<int>> 它的元素类型 std::vector<int>
	int student_index = 0;
	for (std::vector<int> student : student_vector) {
		std::cout << "..student_" << student_index << ", mark_list :: ";
		for (int mark : student) {
			std::cout << mark << '\t';
		}
		std::cout << "\n";
	}
	

	// calculate total, avg
	int tmp_total{ 0 }, tmp_avg{ 0 };
	student_index=  0;
	for (std::vector<int> student : student_vector) {
		std::cout << "..student_" << student_index;
		tmp_total = 0;
		for (int mark : student) {
			tmp_total += mark;
		}
		tmp_avg = tmp_total / 6;
		std::cout << "..total marks :: " << tmp_total
			<< ", average marks :: " << tmp_avg;
		std::cout << "\n";
	}

	return 0;
}


int practice_03() {

	std::cout << "..in day02 practice_03...\n";
	
	{
		/// 需求
		///有一个装有三个学生6个学科分数的vector，请把这个vector传给另一个函数 change_score()函数，
		///在该函数内部 请使用** 基于范围的for循环** 对 vector进行遍历，
		///把vector里面所有低于60分的分数，修改为：100分。

	}

	{	/// 使用二维数组形式
		int student_mark_array[3][6]{
			{100, 90, 59, 79, 80, 27},
			{30, 69, 78, 89, 91, 40},
			{50, 79, 89, 91, 80, 89},
		};

	}

	{	/// 使用vector-vector形式
		std::vector<std::vector<int>> student_mark_vector{
			{ 100, 90, 59, 79, 80, 27},
			{ 30, 69, 78, 89, 91, 40 },
			{ 50, 79, 89, 91, 80, 89 },
		};

		std::vector<int> total_mark;
		std::vector<int> avg_mark;

		/// <summary> 这个怎么弄出来的？
		/// 计算 total, avg
		/// </summary>
		/// <returns></returns>
		int tmp_total{ 0 }, tmp_avg{ 0 }, student_index{ 0 };
		std::cout << "..calculate total and avg. marks for each student, before modification..." << std::endl;
		for (std::vector<int> single_stu_mark : student_mark_vector) {
			tmp_total = 0;
			tmp_avg = 0;
			student_index++;
			for (int single_mark : single_stu_mark) {
				tmp_total += single_mark;
			}
			tmp_avg = tmp_total / 6;
			total_mark.push_back(tmp_total);
			avg_mark.push_back(tmp_avg);
			std::cout << "..total mark for student[" << student_index << "] :: " << tmp_total << "\n"
				<< "..avg mark for student[" << student_index << "] :: " << tmp_avg << "\n";
		}

		/// 将低于 60 的改成 60
		std::cout << "..calculate total and avg. marks for each student, after modification..." << std::endl;
		student_index = 0;
		for (std::vector<int> single_stu_mark : student_mark_vector) {
			tmp_total = 0;
			tmp_avg = 0;
			student_index++;
			for (int single_mark : single_stu_mark) {
				if (single_mark < 60)
					single_mark = 60;
				tmp_total += single_mark;
			}
			tmp_avg = tmp_total / 6;
			total_mark.push_back(tmp_total);
			avg_mark.push_back(tmp_avg);
			std::cout << "..total mark for student[" << student_index << "] :: " << tmp_total << "\n"
				<< "..avg mark for student[" << student_index << "] :: " << tmp_avg << "\n";
		}
	}

	{	///练习vector做参数 
		std::cout << "..in pass vector to function practice...\n";
		std::vector<std::vector<int>> student_mark_vector{
			{ 100, 90, 59, 79, 80, 27},
			{ 30, 69, 78, 89, 91, 40 },
			{ 50, 79, 89, 91, 80, 89 },
		};

		std::vector<std::vector<int>> student_mark_vector_modified;
		student_mark_vector_modified = change_score_value(student_mark_vector);
		change_score_reference(student_mark_vector);

		// 打印，使用基于范围的for循环
		int student_index{ 0 };
		for (std::vector<int> single_student_mark : student_mark_vector_modified) {
			std::cout << "..for student[" << student_index << "] :: ";
			student_index++;
			for (int mark : single_student_mark) {
				std::cout << mark << "\t";
			}
			std::cout << "\n";
		}

		student_index = 0;
		for (std::vector<int> single_student_mark : student_mark_vector) {
			std::cout << "..for student[" << student_index << "] :: ";
			student_index++;
			for (int mark : single_student_mark) {
				std::cout << mark << "\t";
			}
			std::cout << "\n";
		}
	}
	return 0;
}

std::vector<std::vector<int>> change_score_value(std::vector<std::vector<int>> student_mark_vector) {
	/// 将低于 60 的改成 60
	std::cout << "..in chane_score_value::change mark less than 60 to 60..." << std::endl;
	for (std::vector<int> single_stu_mark : student_mark_vector) {
		for (int single_mark : single_stu_mark) {
			if (single_mark < 60)
				single_mark = 60;	// 这里改不了值，为什么
		}
	}
	return student_mark_vector;
}

int change_score_reference(std::vector<std::vector<int>>& student_mark_vector) {
	/// 将低于 60 的改成 60
	std::cout << "..in chane_score_reference::change mark less than 60 to 60..." << std::endl;
	for (std::vector<int> single_stu_mark : student_mark_vector) {
		for (int single_mark : single_stu_mark) {
			if (single_mark < 60)
				single_mark = 60;	// 这里改不了值，为什么
		}
	}
	return 0;
}

/*

..in day02 practice_03...
..calculate total and avg. marks for each student, before modification...
..total mark for student[1] :: 435
..avg mark for student[1] :: 72
..total mark for student[2] :: 397
..avg mark for student[2] :: 66
..total mark for student[3] :: 478
..avg mark for student[3] :: 79
..calculate total and avg. marks for each student, after modification...
..total mark for student[1] :: 469
..avg mark for student[1] :: 78
..total mark for student[2] :: 447
..avg mark for student[2] :: 74
..total mark for student[3] :: 488
..avg mark for student[3] :: 81
..in pass vector to function practice...
..in chane_score_value::change mark less than 60 to 60...
..in chane_score_reference::change mark less than 60 to 60...
..for student[0] :: 100 90      59      79      80      27
..for student[1] :: 30  69      78      89      91      40
..for student[2] :: 50  79      89      91      80      89
..for student[0] :: 100 90      59      79      80      27
..for student[1] :: 30  69      78      89      91      40
..for student[2] :: 50  79      89      91      80      89

D:\W_workPlace\bxg_cpp\day02\build\Debug\day02_normal_practice.exe (process 19188) exited with code 0.
Press any key to close this window . . .

*/