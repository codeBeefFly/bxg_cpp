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
		///��һ��װ��6��ѧ�Ʒ�����vector��������vector������һ������ change_score()������
		///�ڸú����ڲ� ��ʹ��** ���ڷ�Χ��forѭ��** �� vector���б�����
		///��vector�������е���60�ֵķ������޸�Ϊ��100�֡�

	}

	return 0;
}

