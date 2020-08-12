#include<iostream>
#include <vector>

int practice_01();
int practice_02();
int practice_03();

// function overloading, ����������, ����ֻ�����û�ֵ���ݲ���ʵ�ֺ�������
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
		/// ����
		///����һ���ַ������ж������ж��ٸ����֣����ٸ���ĸ��
		///���Ұ�����Ǹ���ĸa �޸�Ϊ��д��ĸA 
		///�޸��õĺ����ǣ�replace���޸���ʼ����λ�ã��޸ĵĺ�糤�ȣ��޸ĳ�ʲ ô�ַ���; 
		///�ж��Ƿ�����ĸ������ʹ�õ��� isalpha() �� isdigit(), ��Ҫ���� #include<ctype.h>
	}

	std::string target_string = "aabb23cccddee12cca";

	// ����1������������ĸ������isalpha() isdigit() ʹ��c++ ���
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

	// ����2����д�����ĸ replace (δ���)
	std::cout << "..target_string before modification :: " << target_string << "\n";
	//int pos = strlen(target_string) - 1;	// strlen �� C �� stl
	//target_string.replace(target_string.length() - 1, 1, toupper(target_string.at(target_string.length() - 1)));


	return 0;
}


int practice_02() {

	std::cout << "..in day02 practice_02...\n";

	{
		/// ����
		///ʹ�ö�άvector��¼����ѧ����6��ѧ�Ƴɼ������Ҽ���ÿ��ѧ�����ܷ֣�ƽ���֡�
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

	// show info, ʹ�� ���ڷ�Χfor�ı���	��Ҫ����Ԫ�ص�����
	// ���� std::vector<std::vector<int>> ����Ԫ������ std::vector<int>
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
		/// ����
		///��һ��װ������ѧ��6��ѧ�Ʒ�����vector��������vector������һ������ change_score()������
		///�ڸú����ڲ� ��ʹ��** ���ڷ�Χ��forѭ��** �� vector���б�����
		///��vector�������е���60�ֵķ������޸�Ϊ��100�֡�

	}

	{	/// ʹ�ö�ά������ʽ
		int student_mark_array[3][6]{
			{100, 90, 59, 79, 80, 27},
			{30, 69, 78, 89, 91, 40},
			{50, 79, 89, 91, 80, 89},
		};

	}

	{	/// ʹ��vector-vector��ʽ
		std::vector<std::vector<int>> student_mark_vector{
			{ 100, 90, 59, 79, 80, 27},
			{ 30, 69, 78, 89, 91, 40 },
			{ 50, 79, 89, 91, 80, 89 },
		};

		std::vector<int> total_mark;
		std::vector<int> avg_mark;

		/// <summary> �����ôŪ�����ģ�
		/// ���� total, avg
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

		/// ������ 60 �ĸĳ� 60
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

	{	///��ϰvector������ 
		std::cout << "..in pass vector to function practice...\n";
		std::vector<std::vector<int>> student_mark_vector{
			{ 100, 90, 59, 79, 80, 27},
			{ 30, 69, 78, 89, 91, 40 },
			{ 50, 79, 89, 91, 80, 89 },
		};

		std::vector<std::vector<int>> student_mark_vector_modified;
		student_mark_vector_modified = change_score_value(student_mark_vector);
		change_score_reference(student_mark_vector);

		// ��ӡ��ʹ�û��ڷ�Χ��forѭ��
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
	/// ������ 60 �ĸĳ� 60
	std::cout << "..in chane_score_value::change mark less than 60 to 60..." << std::endl;
	for (std::vector<int> single_stu_mark : student_mark_vector) {
		for (int single_mark : single_stu_mark) {
			if (single_mark < 60)
				single_mark = 60;	// ����Ĳ���ֵ��Ϊʲô
		}
	}
	return student_mark_vector;
}

int change_score_reference(std::vector<std::vector<int>>& student_mark_vector) {
	/// ������ 60 �ĸĳ� 60
	std::cout << "..in chane_score_reference::change mark less than 60 to 60..." << std::endl;
	for (std::vector<int> single_stu_mark : student_mark_vector) {
		for (int single_mark : single_stu_mark) {
			if (single_mark < 60)
				single_mark = 60;	// ����Ĳ���ֵ��Ϊʲô
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