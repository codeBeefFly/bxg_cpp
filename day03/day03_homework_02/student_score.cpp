/*

�����ۺ���Ŀ
1. ����ṹ��stu, ����ѧ�����������ַ�������ѧ�ţ��ַ��������ɼ���vector<int>��6��ѧ��

2. ����һ��vector���������������ġ���������ѧ������Ϣ ����ʹ��ѧ����ָ�����͡�
	���vectorҲ��һ��ָ�����ͣ�������Ӧ���ɺ���createContainer ������������
   1.  vector< stu* > *stu_vector;

3. ����һ��ȫ�ֺ���(ֱ����main.cpp�ж���)createContainer�����ڴ������ѧ����vector����
	1.�ú���û�з���ֵ�����ö���ָ��ķ�ʽ����vector��ָ�롣


4. ��ʼ���ɼ���
	1. ����initScore����¼��ѧ������Ϣ�� ���� , ѧ�� �� 6��ѧ�Ƴɼ�
	2. ����initScore����Ϊ����ĸ�ֵ���������ǽ��������̵�¼�빦�ܣ�
		�ڸú�����ȡ�����������֮�󣬵���initStu���ѧ����ʼ��������
	3. ����һ������initStu,ר������ѧ�����ݵĳ�ʼ�����������ղ������£�
		void initStu(������ ѧ�� �� 6��ѧ�Ƴɼ���vector , stu_vector);
		���У��������͡�
		���磺
			void  initStu(
				string&& name ,
				string&& no ,
				vector<int>& score_vector ,
				vector<stu*> *stu_vector
			);
	4. ����Ҫ������ֵ����ֵ�����⣬��Ϊ���ռ���¼���ʱ������ֵ�����գ����ǳ�ʼ��ѧ���ĺ���
		���ܵ�����ֵ�����Դ˴���Ҫʹ�õ�move���������鿴��Ƶ��22_��ҵ-��ֵ����ֵ����
5. ���³ɼ���
	1. ��������main.cpp�ж���ȫ�ֺ���updateToSeventy ��updateToEighty ��updateToNinety ��
		��Ӧ���Ǹ��³ɼ�Ϊ70,80,90
	2. ��ִ�е���updateScore����֮ǰ��Ӧ����ѯ��Ҫ�޸ĳ�ʲô�ɼ�������ѡ��Ϊ70,80,90.
	3. ���ݶ�Ӧ�ķ�����������updateScore���������Ҵ���������¾�������ĺ���ָ��

6. ��ӡ�ɼ���
	1. �������ִ�ӡ���� ���ڷ�Χ��forѭ����ʽ��printForRange  ��ʹ�ú�for i �ķ�ʽ��printForI.
	2. ��ִ��printScore , Ӧ����ѯ���û���Ҫʹ�ú��ַ�ʽ��ӡ(1: ���ڷ�Χfor��ʽ�� 2: ʹ��forI��ʽ)
	3. ���ݶ�Ӧ��ѡ��������printScore���������Ҵ��������ӡ��ʽ�ĺ���ָ�롣


7. ʹ�÷���ʽд���� stu.h  , stu.cpp , main.cpp
   1. stu.h ���� �ṹ��stu�������� ��������������
   2. stu.cpp �������������ľ���ʵ�ġ�
   3. main.cpp ��Ϊ��������

8. ���Ҫ�����˻�������ѧ�����ڴ�ռ䡣


ע�⣺ȫ�ֺ�����ָ�� main.cpp �ж���ĺ���

*/


#include <iostream>
#include <vector>
#include "stu.h"
 

void createContainer(std::vector<student*>** student_vector_ptr);
void initStudent(
	std::string&& name,							// ������ֵ����
	std::string&& id,							// ������ֵ����
	std::vector<int>& score_vector,				// ������ֵ����
	std::vector<student*>* student_vector	
);

// ���������صĺ���
void updateToSeventy();
void updateToEighty();
void updateToNinety();

// �����ӡ��صĺ���
void printForIndex(std::vector<student*>* student_vector);
void printForRange(std::vector<student*>* student_vector);


// �������
int main() {

	// 1. ����һ������������װ����ѧ����ʹ��ָ��
	std::vector<student*>* student_vector = nullptr;

	// 2. ��������, ����Ϊ����ָ��, ��һ��ָ��ĵ�ַ
	createContainer(&student_vector);

	// 3. ��ʼ���ɼ�
	initScore(student_vector, initStudent);	// ��������=�����ĵ�ַ				    

	// 4. ���³ɼ�	 
	//updateScore(student_vector);

	// 5. ��ӡ�ɼ�
	std::cout << "..ѡ���ӡ��ʽ��1. ���ڷ�Χ��2. ���ڽű� ::\t";
	int print_choice;
	std::cin >> print_choice;
	
	switch (print_choice)
	{
	case 1:
		printScore(student_vector, printForRange);
		break;
	case 2:
		printScore(student_vector, printForIndex);
		break;
	default:
		std::cout << "..�������...\n";
		break;
	}


	 			 
	return 0;
}



void createContainer(std::vector<student*>** student_vector_ptr) {
	*student_vector_ptr = new std::vector<student*>();
}


void initStudent(
	std::string&& name,							// ������ֵ����
	std::string&& id,							// ������ֵ����
	std::vector<int>& score_vector,				// ������ֵ����
	std::vector<student*>* student_vector
) {

	/*
	
	// ��һ�ֲ�����Ҫ���д��
	// stu �Ǿֲ�������ջ�ڴ����ռ䣬����ִ����Ϻ�����
	student stu;
	stu.name = name;
	stu.id = id;
	stu.score_vector = score_vector;

	(*student_vector).push_back(&stu);	// ���ݵ���ѧ������ĵ�ַ������ִ����Ϻ��ڴ��ͷ�

	*/
	
	// ����Ҫ���д��
	// ʹ�� new �ڶ��ڴ��п���һ���ռ䣬����һ�� student ���͵�ָ��
	// ͨ��ָ������õõ� student ���͵Ķ���
	student* stu_ptr = new student;		// stu_ptr = student ���͵ĵ�ַ�������ַ�ڶ��ڴ�
	(*stu_ptr).name = name;
	(*stu_ptr).id = id;
	(*stu_ptr).score_vector = score_vector;

	(*student_vector).push_back(stu_ptr);

}


void printForIndex(std::vector<student*>* student_vector) {
	
	std::cout << "..in printForIndex()...\n";
	
	for (int i = 0; i < (*student_vector).size(); i++) {
		std::cout << "..ѧ��[" << i + 1 << "]����Ϣ...\n";
		student* stu_ptr = (*student_vector).at(i);	// student_vector ��ѧ��������һ��ָ��
		std::cout << "...ѧ������:: " << (*stu_ptr).name << "\n";
		std::cout << "...ѧ��ѧ��:: " << (*stu_ptr).id << "\n";

		for (int j = 0; j < (*stu_ptr).score_vector.size(); j++) {
			std::cout << "...ѧ��[" << j + 1 << "]�ɼ�:: " << (*stu_ptr).score_vector.at(j) << "\n";
		}
	}
}


void printForRange(std::vector<student*>* student_vector) {
	
	std::cout << "..in printForRange()...\n";
	
	int student_index{ 0 };
	for (student* stu_ptr : (*student_vector)) {
		std::cout << "..ѧ��[" << student_index + 1 << "]����Ϣ...\n";
		student_index++;
		std::cout << "...ѧ������:: " << (*stu_ptr).name << "\n";
		std::cout << "...ѧ��ѧ��:: " << (*stu_ptr).id << "\n";

		int subject_index{ 0 };
		for (int score : (*stu_ptr).score_vector) {
			std::cout << "...ѧ��[" << subject_index + 1 << "]�ɼ�:: " << (*stu_ptr).score_vector.at(subject_index) << "\n";
			subject_index++;
		}

	}
}