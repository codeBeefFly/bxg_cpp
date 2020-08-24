/*

����
1. ����ѧ���� Student������
	1. ���ԣ�������name��ָ�����ͣ�������vector�洢��
	2. ������putScore() ������ӷ��������� int ���ͷ�����
	3. ������updateScore() ���ڸ��¸�ѧ������������60�ָ�Ϊ60��
	4. ������showInfo() �������ѧ�� �������ܷ֣�ƽ���֣����Ʒ���

2. ѧ�������ʽд�� Student.h, Student.cpp
	1. Student.h����������+����
	2. Student.cpp��ʵ��

3. �� main() �У�����ֲ����� vector<Student*> stu_vector

4. ��������ѧ����a��b��c��c��b����һ��

5. ���ÿ�������ķ�ʽ���� c��Ȼ�����޸ĸ�ѧ��������

����Ҫ��
1. ���캯�������޲Σ���һ�����������������������ֹ�������

2. ���ó�ʼ���б�ķ�ʽ���幹�캯��

3. ���캯��Ҫ���ֳ�ί�л���

4. ѧ�����е� name ���Գ�ʼֵΪ��ָ�룬ע�⿽�����⡣

5. stu�������к������� stu.cpp ��ʵ�֣�stu.h����������
	����
	updateScore(), showInfo(), ���캯��(3��), ��������(1��), �������캯��(1��)

6. ѧ���� name ��ָ��, ��������������, Ҫ�ͷ����ָ��

*/


#include <iostream>
#include "Student.h"


int main() {
	
	std::cout << "..in homework_student_class_01...\n";

	//1. ��������
	std::vector<Student*> stu_vector;

	Student* tmp_stu = nullptr;

	//2. ���̻�ȡѧ�������ݣ�ֻ�û�ȡ����ѧ���ɼ�����һ��ѧ���ɼ�ʹ�ÿ���
	// ʹ������for loop������������+���䣬�ڲ���շ���
	for (int i = 0; i < 2; i++) {
		std::cout << "..����ѧ��[" << i + 1 << "]..\n"
			<<"...����::\t";
		std::string tmp_name;
		std::cin >> tmp_name;

		std::vector<int> score_vector;
		for (int j = 0; j < 6; j++) {
			std::cout << "...ѧ��[" << j + 1 << "]�ɼ�::\t";
			int tmp_score;
			std::cin >> tmp_score;
			score_vector.push_back(tmp_score);
		}

		////����ѧ������һ��ķ�ʽ
		//Student stu;
		//*stu.name = tmp_name;
		//stu.score_vector = score_vector;

		////����ѧ������ʹ���вι���ķ�ʽ
		//Student tmp_stu(&tmp_name, score_vector);
		////Student tmp_stu = new Student(&tmp_name, score_vector);
		//
		////����
		//std::cout << &tmp_stu << "\n";
		//std::cout << *tmp_stu.name << "\n";		// û��ֵ
		//for (int score : tmp_stu.score_vector) {
		//	std::cout << "score::\t" << score << "\t";
		//}

		//Student* tmp_stu = new Student(&tmp_name, score_vector);
		tmp_stu = new Student(&tmp_name, score_vector);

		//Student stu = tmp_stu;

		////��ѧ�������ƽ�������
		//std::cout << &stu << "\n";
		//stu_vector.push_back(&stu);

		//��ѧ�������ƽ�������
		//std::cout << &tmp_stu << "\n";
		//stu_vector.push_back(&tmp_stu);
		std::cout << tmp_stu << ", " << *(*tmp_stu).name << "\n";
		stu_vector.push_back(tmp_stu);
	}

	// ��������⣬û�����ݣ���֪��ʲô���
	std::cout << *(*tmp_stu).name << "\n";

	// ʹ������ showInfo ��ʽ
	for (Student* stu : stu_vector) {
		std::cout << "..log..��ӡѧ���ɼ�...\n";

		std::cout << "..ѧ������::\t" << *(*stu).name << "\n";
		(*stu).showInfo();
	}

	// ��������ѧ��������������ǰ������ֻ������ѧ��
	//Student* stu_c = stu_vector.back();			//���Ѿ���ֵ�ˣ�����+�ɼ�����������������ֵ�������ѵڶ���ѧ���ĵ�ַ��û�ˣ�����
	
	Student stu_c = *(stu_vector.back());			//�Ե� 

	std::cout << "..���������ѧ������::\t";
	std::string tmp_name;
	std::cin >> tmp_name;
	*stu_c.name = tmp_name;


	// ʹ������ showInfo ��ʽ
	for (Student* stu : stu_vector) {
		std::cout << "..log..��ӡѧ���ɼ�...\n";

		(*stu).showInfo();
	}

	///3. �޸ĳɼ�
	//����ѧ�������޸�ѧ���ɼ�
	for (Student* stu : stu_vector) {
		std::cout << "..log::�޸�ѧ���ɼ�...\n";

		(*stu).updateScore(nullptr);
	}

	///4. ��ӡ�ɼ�
	
	/*	��ͳ�ķ�ʽ
	
	//����ѧ�����󣬴�ӡѧ���ɼ�
	for (Student* stu : stu_vector) {
		std::cout << "..log::��ӡѧ���ɼ�...\n";
		
		std::cout << "..ѧ������::\t" << (*stu).name << "\n";
		int score_index{ 0 };
		for (int score : (*stu).score_vector) {
			std::cout << "..����[" << score_index + 1 << "]::\t" << score << "\n";
			score_index++;
		}
	}
	
	*/

	// ʹ������ showInfo ��ʽ
	for (Student* stu : stu_vector) {
		std::cout << "..log..��ӡѧ���ɼ�...\n";

		(*stu).showInfo();
	}


	return 0;
}
