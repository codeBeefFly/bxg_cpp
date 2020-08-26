/*

����

1. ����ѧ���� Student������
	1. ���ԣ�������ѧ�š�ѧУ������
	2. ����Ϊָ�����ͣ�ѧ��Ϊ��ͨ�ַ�����ѧУΪ��̬��Ա������vector<int>

2. ѧ����Ӧ�þ��� stu.h �� stu.cpp �����ļ�
	1. stu.h �������������Լ�����
	2. stu.cpp Ӧ����Ϊ�����������ľ���ʵ��  ���� ���� ����

3. �� main �������棬����ֲ����� vector<stu *> stu_vector

4. ����ȫ�ֺ��� initStu ��ʼ��ѧ����Ϣ��������Ҫ¼��3��ѧ����Ϣ

5. ����ȫ�ֺ��� updateStu ����ѧ���ɼ������ú���ָ��ķ�ʽ����
	�����ڲ���ѯ�ʾ�����µ�ʲô������Ȼ��ʹ�� switch �ж�
	�������ݽ�ȥ��Ӧ�ĺ���ָ��

6. ����ȫ�ֺ��� printStu ���ڴ�ӡѧ����Ϣ��Ҫ��ѧ������������� <<
	Ȼ��ʹ�� cout << s << endl, sΪѧ������ķ�ʽ��ӡ��ѧ����Ϣ���鿴�ʼǡ�

7. ����ѡ��
	����ȫ�ֺ��� deleteStu ����ɾ��ѧ�����ؼ���¼��ѧ��ѧ�ţ�
	ƥ��֮�󣬴�������ɾ����ѧ����

*/

#include <iostream>
#include "Student.h"


void initStu(std::vector<Student*>& student_vector);
void updateStu(std::vector<Student*>& student_vector, void (*update_score)(int& score));	// ����ָ��ķ�ʽ����
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

	// ��ʼ����������ѧ��
	initStu(stu_vector);

	// ����ѧ���ɼ�
	updateStu(stu_vector, update2_60);

	// ��ӡѧ���ɼ�
	printStu_normal(stu_vector);
	printStu_op_overload(stu_vector);

	// ɾ��ѧ��
	deleteStu(stu_vector);

	return 0;
}


void initStu(std::vector<Student*>& student_vector) {
	std::cout << "\n************ ��ʼ��ѧ�� ************\n";

	for (int i = 0; i < 3; i++) {
		std::cout << "..����ѧ��[" << i + 1 << "]����::\t";
		std::string tmp_name;
		std::cin >> tmp_name;

		std::cout << "..����ѧ��[" << i + 1 << "]id::\t";
		std::string tmp_id;
		std::cin >> tmp_id;

		std::vector<int> score_vector;
		int tmp_score{ 0 };
		for (int i = 0; i < 6; i++) {
			std::cout << "..�����[" << i + 1 << "]�Ƴɼ�::\t";
			std::cin >> tmp_score;
			score_vector.push_back(tmp_score);
		}
		
		Student* stu = new Student(tmp_name, tmp_id, score_vector);
		
		student_vector.push_back(stu);
	}
}


void updateStu(std::vector<Student*>& student_vector, void (*update_score)(int& score)) {
	std::cout << "\n************ ����ѧ���ɼ� ************\n";

	for (Student* student : student_vector) {
		for (int& score : student->score_vector) {
			update2_60(score);
		}
	}
}


void printStu_normal(std::vector<Student*> student_vector) {
	std::cout << "\n************ ��ӡѧ����Ϣ(normal) ************\n";
	
	int student_index{ 0 };
	for (Student* student : student_vector) {
		std::cout << "..ѧ��[" << student_index++ << "]...\n"
			<< "...����::\t" << *student->name << "\n"
			<< "...id::\t" << student->id << "\n";

		//int score_index{ 0 };
		std::cout << "..����::\t";
		for (int score : student->score_vector) {
			//std::cout << "...ѧ��[" << score_index++	 << "]����::\t" << score << "\n";
			std::cout << score << "\t";
		}
		std::cout << "\n";
	}
}


void printStu_op_overload(std::vector<Student*> student_vector) {
	std::cout << "\n************ ��ӡѧ����Ϣ(op_overload) ************\n";

	int student_index{ 0 };
	for (Student* student : student_vector) {
		std::cout << "..ѧ��[" << student_index++ << "]��Ϣ����...\n";
		std::cout << *student << "\n";
	}
}


void deleteStu(std::vector<Student*>& student_vector) {
	std::cout << "\n************ ɾ��ѧ������ ************\n";

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
	out << "..ѧ������::\t" << *stu.name << "\n"
		<< "..ѧ��id::\t" << stu.id << "\n"
		<< "..ѧ�Ʒ���::\t";
	for (int score : stu.score_vector) {
		out << score << "\t";
	}
	//out << "\n";

	return out;
}

