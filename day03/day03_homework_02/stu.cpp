#include "stu.h"

/*

void initStudent(
	std::string&& name,							// ������ֵ����
	std::string&& id,							// ������ֵ����
	std::vector<int>& score_vector,				// ������ֵ����
	std::vector<student*>* student_vector
) 

*/

typedef void(*initStudent_ptr)(
	std::string&& name,							// ������ֵ����
	std::string&& id,							// ������ֵ����
	std::vector<int>& score_vector,				// ������ֵ����
	std::vector<student*>* student_vector
	);


//void initScore(		// ����ָ����Ϊ������ʽ2��ʹ�� typedef
//	std::vector<student*>* student_vector,
//	initStudent_ptr initStudent_fun
//) {

void initScore(	// ����ָ����Ϊ������ʽ1
	std::vector<student*>* student_vector,
	void (*initStudent_ptr)(
			std::string&& name,							// ������ֵ����
			std::string&& id,							// ������ֵ����
			std::vector<int>& score_vector,				// ������ֵ����
			std::vector<student*>* student_vector
		)

) {
	
	for (int i = 0; i < 3; i++) {	// ѭ��3�δ���3��ѧ������ѧ������Ҫ�ŵ�����
		
		std::cout << "..�����[" << i + 1 << "]��ѧ������Ϣ...\n";
		
		std::cout << "...ѧ������::\t";
		std::string name;
		std::cin >> name;

		std::cout << "...ѧ��ѧ��::\t";
		std::string id;
		std::cin >> id;

		std::cout << "...ѧ���ɼ�::\n";
		std::vector<int> score_vector;
		for (int j = 0; j < 6; j++) {
			std::cout << "....��[" << j + 1 << "]�Ƴɼ�::\t";
			int score;
			std::cin >> score;
			score_vector.push_back(score);
		}

		// ����һ��ѧ�����󣬲��������������� iniStudent ���� 
		// ����1��ʹ��typedef ���¸�����ָ������
		//initStudent_fun(move(name), move(id), score_vector, student_vector);
		// ����2��ֱ��ʹ�ú�����
		initStudent_ptr(move(name), move(id), score_vector, student_vector);
		

	}
}

void updateScore(std::vector<student*>* student_vector, void (*update_ptr)(int*)) {
	for (student* student : (*student_vector)) {
		for (int& score : (*student).score_vector) {	// ʹ�����þͿ����޸�vector�е�Ԫ��ֵ
			if (score < 60) {
				update_ptr(&score);
			}
		}
	}
}

void printScore(std::vector<student*>* student_vector, void (*print_ptr)(std::vector<student*>*)) {
	print_ptr(student_vector);
}