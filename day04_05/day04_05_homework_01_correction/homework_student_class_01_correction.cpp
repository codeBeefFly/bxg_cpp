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


int main(){
	
	std::cout << "..in homework_student_class_01_correction...\n";


	std::vector<Student*> student_vector;

	// ��ȡѧ����Ϣ
	std::cout << "\n********����ѧ����Ϣ********\n";
	for (int i = 0; i < 2; i++) {
		std::cout << "..ѧ������::\t";
		std::string name;
		std::cin >> name;

		std::vector<int> score_vector{};
		for (int j = 0; j < 6; j++) {
			std::cout << "..ѧ��[" << j + 1 << "]�ɼ�::\t";
			int score;
			std::cin >> score;
			score_vector.push_back(score);
		}

		// �ڶ��д���ѧ������
		Student* stu = new Student(name, score_vector);
		student_vector.push_back(stu);

		//delete stu;		// ����
	}


	// ��ʾѧ����Ϣ
	std::cout << "\n********��ʾѧ����Ϣ********\n";
	for (Student* stu : student_vector) {
		(*stu).showInfo();
	}

	// ��������һ��ѧ��
	std::cout << "\n********����ѧ����Ϣ********\n";
	Student stu = *student_vector[1];	// ��������stu����ջ���洴���Ķ���delete����û����
	std::cout << "..ѧ��C����::\t";
	std::string tmp_name;
	std::cin >> tmp_name;
	*stu.name = tmp_name;
	student_vector.push_back(&stu);

	// �ٿ�������һ��ѧ��
	//std::cout << "\n********����ѧ����Ϣ********\n";
	//Student* stu = new Student;
	//*stu = *student_vector[1];
	//std::cout << "..ѧ��C����::\t";
	//std::string tmp_name;
	//std::cin >> tmp_name;
	//*(*stu).name = tmp_name;
	//student_vector.push_back(stu);


	// �޸�ѧ����Ϣ
	std::cout << "\n********�޸�ѧ����Ϣ********\n";
	for (Student* stu : student_vector) {
		(*stu).updateScore();
	}


	// ��ʾѧ����Ϣ
	std::cout << "\n********��ʾѧ����Ϣ********\n";
	for (Student* stu : student_vector) {
		(*stu).showInfo();
	}


	// �ͷŶѿռ�
	// delete �� new �����Ķ��󣨶��еĶ��󣩣�������ջ�еĶ���
	std::cout << "\n********�ͷ�ѧ������********\n";
	for (Student* stu : student_vector) {
		std::cout << "..��ַ::\t" << stu << "\n";
		delete stu;
	}

	
	return 0;
}