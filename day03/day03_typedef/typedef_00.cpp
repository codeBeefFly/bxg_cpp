/*
typedef ���������Լ�ϰ�ߵ����֣��������е��������ơ� 
�﷨�� `typedef ��֪�������� �Զ�������`


����
1. ʹ�� typedef ���� int �� vector<int>
2. ʹ�õ�Դ�ļ�����ʽд��
3. ��ͨ��д��

*/


#include<iostream>
#include<vector>


// ʹ�� typedef ����������
typedef int my_int;
typedef std::vector<int> vector_int;


// prototype
void printScores(vector_int);


// ��ں���
int main() {

	vector_int score_vector{ 1, 2, 3, 4, 5 };

	printScores(score_vector);

	return 0;
}


// ���� prototype
// ���д�� printScore .. 
// unresolved external symbol error :: δ������ⲿ���Ŵ���
void printScores(vector_int score_vector) {
	std::cout << "..in printScroe...\n..score_list ::\t";
	for (my_int score : score_vector) {
		std::cout << score << "\t";
	}

}