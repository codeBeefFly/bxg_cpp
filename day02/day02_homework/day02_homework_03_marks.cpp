/*
����

3. ʹ�ö�άvector ���ڱ������������ġ����壬���˵�6��ѧ�Ƶĳ�
����
a. ����һ����άvector�����У�score_vector�������洢����
ѧ����6��ѧ�Ƴɼ�
b. ����һ��initScore��vector<vector>����������Ӽ���¼��
�ɼ�
c. ����һ������updateScore��vector<vector>�� �����ڸ���
��������ÿ���˵Ĳ�����ĳɼ�ȫ���޸ĳ�99�֣�
d. ����һ������ printScore ��vector<vector>����������ӡ��
���˵�ÿ��ѧ�Ƴɼ���
e. Ҫ��ʹ�ú���ԭ�͡�����ʽд����ͷ�ļ���Դ�ļ��� ����
���������ã����ڷ�Χforѭ����
f. ��ֹ����ȫ�־�̬vector ��Ҫ��2 ��3 ��4 ����ĺ���ҪЯ
���������Ѷ�άvector���ݽ�ȥ��
g. ���٣� Ӧ��Ҫ�������ã�������µĲ����޷�ʵ�֡�����
ʹ�ÿɿ���������á�

*/

#include <iostream>
#include "basic_operation.h"


int main() {
	std::cout << "..day02_homework_03_marks..." << std::endl;

	std::vector<std::vector<int>> score_vector;		// // empty vector of ints

	initScore(score_vector);

	printScore(score_vector);

	updateScore(score_vector);

	printScore(score_vector);

	return 0;
}