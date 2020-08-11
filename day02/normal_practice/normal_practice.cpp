#include<iostream>
#include <vector>

int practice_01();
int practice_02();
int practice_03();


int main(){

	//practice_01();		// not finished
	practice_02();		

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
		///有一个装有6个学科分数的vector，请把这个vector传给另一个函数 change_score()函数，
		///在该函数内部 请使用** 基于范围的for循环** 对 vector进行遍历，
		///把vector里面所有低于60分的分数，修改为：100分。

	}

	return 0;
}

