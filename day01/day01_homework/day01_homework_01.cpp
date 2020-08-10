//����ҵ������
//1. ʹ�������ռ䶨������ѧ��������������������ѧ�š���ʾ6��ѧ�Ƴɼ�������
//2. ѭ����ȡ����ѧ����������Ϣ����ע�⣺ÿ��ѧ����6�Ƴɼ�Ҫ��¼��
//3. ������ɺ�չʾÿ��ѧ�����ܷ֡�ƽ���֡�

#include <iostream>

int get_marks();
int show_marks();
int calculate_total();

namespace student_A {
	std::string name = "student_A";
	int id = 0000;
	//3. �Զ����������С
	//int marks_array[]{ 0 };		// ��������ʼ�����飬���鳤��û��ָ�������ݺ����ʼ���������ƶϡ�
	int marks_array[6]{ 0 };		// ��������ʼ�����飬���鳤��û��ָ�������ݺ����ʼ���������ƶϡ�
	int total_mark = 0;
	int avg_mark = 0;
}

namespace student_B {
	std::string name = "student_B";
	int id = 0000;
	int marks_array[6]{ 0 };	// ��������ʼ������
	int total_mark = 0;
	int avg_mark = 0;
}

namespace student_C {
	std::string name = "student_C";
	int id = 0000;
	int marks_array[6]{ 0 };
	int total_mark = 0;
	int avg_mark = 0;
}



int main() {

	std::cout << "..in day01_homework_01.cpp..." << std::endl;

	get_marks();
	show_marks();

	return 0;
}


int get_marks() {
	std::cout << "..in get_marks..." << std::endl;

	int tmp_id = 0;

	// student_A
	std::cout << "..enter student_A id :: ";
	std::cin >> tmp_id;
	student_A::id = tmp_id;

	std::cout << "..enter student_A 6 subject marks :: \n";
	for (int i = 0; i < 6; i++) {
		int tmp_mark;
		std::cout << "..enter student_A subject[" << i+1 << "] mark ::";
		std::cin >> tmp_mark;
		student_A::marks_array[i] = tmp_mark;
	}

	// student_B
	std::cout << "..enter student_B id :: ";
	std::cin >> tmp_id;
	student_B::id = tmp_id;

	std::cout << "..enter student_B 6 subject marks :: \n";
	for (int i = 0; i < 6; i++) {
		int tmp_mark;
		std::cout << "..enter student_B subject[" << i+1 << "] mark ::";
		std::cin >> tmp_mark;
		student_B::marks_array[i] = tmp_mark;
	}

	// student_C
	std::cout << "..enter student_C id :: ";
	std::cin >> tmp_id;
	student_C::id = tmp_id;

	std::cout << "..enter student_C 6 subject marks :: \n";
	for (int i = 0; i < 6; i++) {
		int tmp_mark;
		std::cout << "..enter student_C subject[" << i+1 << "] mark ::";
		std::cin >> tmp_mark;
		student_C::marks_array[i] = tmp_mark;
	}

	return 0;
}

int show_marks() {
	std::cout << "..in show_marks...\n"
		<< "..enter choice...\n"
		<< "..0-total marks, 1-avg marks, 2-exit program\n"
		<< "..your choice :: ";

	while (true) {

		int choice;
		std::cin >> choice;
		
		if (choice != 0 && choice != 1 && choice != 2) {
			std::cout << "..enter valide choice number {0, 1, 2}..\n";
			continue;
		}
		
		// ʹ�� || C6289
		//if (std::move(choice) != 0 && std::move(choice) != 1 && std::move(choice) != 2) {
		//	std::cout << "..enter valide choice number {0, 1, 2}..\n";
		//	continue;
		//}

		// ��ֵ����
		// reinterpret_cast<>():: ��С��������Ķ���/���� ת���ɼ��������������
		//if (reinterpret_cast<int&&>(choice) != 0 || reinterpret_cast<int&&>(choice) != 1 || reinterpret_cast<int&&>(choice) != 2) {
		//	std::cout << "..enter valide choice number {0, 1, 2}..\n";
		//	continue;
		//}

		std::cout << "..choice entered :: " << choice << std::endl;

		switch (choice)
		{
		case 0:
			std::cout << "..calculating all student total marks..." << std::endl;
			calculate_total();
			std::cout << "student_A total mark :: " << student_A::total_mark << std::endl;
			std::cout << "student_B total mark :: " << student_B::total_mark << std::endl;
			std::cout << "student_C total mark :: " << student_C::total_mark << std::endl;
			std::cout << "..exiting program..." << std::endl;
			return 0;
			break;
		case 1:
			std::cout << "..calculating all student avg marks..." << std::endl;
			calculate_total();
			//student_A
			student_A::avg_mark = student_A::total_mark / 6;
			//student_B
			student_B::avg_mark = student_B::total_mark / 6;
			//student_C
			student_C::avg_mark = student_C::total_mark / 6;
			std::cout << "student_A average mark :: " << student_A::avg_mark << std::endl;
			std::cout << "student_B average mark :: " << student_B::avg_mark << std::endl;
			std::cout << "student_C average mark :: " << student_C::avg_mark << std::endl;
			std::cout << "..exiting program..." << std::endl;
			return 0;
			break;
		case 2:
			std::cout << "..exiting program..." << std::endl;
			return 0;
			break;
		default:
			break;
		}
	}

	return 0;
}


int calculate_total() {
	// student_A
	for (int single_mark : student_A::marks_array) {	//C++11 ���ṩ�� for ѭ��
		student_A::total_mark += single_mark;
	}
	// student_B
	for (int single_mark : student_B::marks_array) {
		student_B::total_mark += single_mark;
	}
	// student_C
	for (int single_mark : student_C::marks_array) {
		student_C::total_mark += single_mark;
	}

	return 0;
}



/*

output
..in day01_homework_01.cpp...
..in get_marks...
..enter student_A id :: 0001
..enter student_A 6 subject marks ::
..enter student_A subject[1] mark ::1
..enter student_A subject[2] mark ::1
..enter student_A subject[3] mark ::1
..enter student_A subject[4] mark ::1
..enter student_A subject[5] mark ::1
..enter student_A subject[6] mark ::1
..enter student_B id :: 0002
..enter student_B 6 subject marks ::
..enter student_B subject[1] mark ::2
..enter student_B subject[2] mark ::2
..enter student_B subject[3] mark ::2
..enter student_B subject[4] mark ::2
..enter student_B subject[5] mark ::2
..enter student_B subject[6] mark ::2
..enter student_C id :: 0003
..enter student_C 6 subject marks ::
..enter student_C subject[1] mark ::3
..enter student_C subject[2] mark ::3
..enter student_C subject[3] mark ::3
..enter student_C subject[4] mark ::3
..enter student_C subject[5] mark ::3
..enter student_C subject[6] mark ::3
..in show_marks...
..enter choice...
..0-total marks, 1-avg marks, 2-exit program
..your choice :: 0
..choice entered :: 0
..calculating all student total marks...
student_A total mark :: 2	// �����	int marks_array[]{ 0 };	 ������������ԭ��δ֪
student_B total mark :: 13
student_C total mark :: 18
..exiting program...


*/