/*
����

1. ����ṹ��stu, ����ѧ�����������ַ�������ѧ�ţ��ַ��������ɼ���vector<int>��6��ѧ��

2. ����һ��vector���������������ġ���������ѧ������Ϣ ����ʹ��ѧ����ָ�����͡���

   1.  vector< stu* > stu_vector;

3. ����ѧ������new�ķ�ʽ���������������ڶ��ڴ��С�

4. ����initScore��������¼��ѧ������Ϣ�� ���� , ѧ�� �� 6��ѧ�Ƴɼ�

5. ����updateScore�����������ѧ���ĳ��š��ɼ�С��60�ģ�����Ϊ60

6. ����printScore������ӡѧ������Ϣ�� ������ѧ�š��ܷ֡�ƽ����

7. ʹ�÷���ʽд���� stu.h  , stu.cpp , main.cpp

   1. stu.h ���� �ṹ��stu�������� ��������������
   2. stu.cpp �������������ľ���ʵ�ġ�
   3. main.cpp ��Ϊ��������

8. ������������vector��ʱ����ʹ��ָ�����ʹ��ݡ�

   initScore(vector <int> & score_vector)

   initScore(vector <stu*>  *score_vector)

*/

#include <iostream>
#include "stu.h"


int main() {

	std::cout << "..in day03_homework..." << std::endl;

	std::vector<student*> stu_vector;

	// ��ʼ���ɼ�
	initScore(stu_vector);

	// ���³ɼ�
	updateScore(stu_vector);

	// ��ӡ�ɼ�
	printScore(stu_vector);

	return 0;
}