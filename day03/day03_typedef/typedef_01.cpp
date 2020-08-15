/*
typedef ���������Լ�ϰ�ߵ����֣��������е��������ơ� 
�﷨�� `typedef ��֪�������� �Զ�������`


����
1. ʹ�� typedef ���� int �� vector<int>
2. ʹ�õ�Դ�ļ�����ʽд��
3. ����ʾ�����룬ʹ��`typedef` �򻯺���ָ�� , 
ʵ�ֵĹ��ܶ���һ���ģ�ֻ�Ǵ������Щ

*/


#include<iostream>
#include<vector>


// ���¶����������
typedef int my_int;
typedef std::vector<int> vector_int;

// ���¶���һ������ָ��
// typedef ����ָ�� �﷨
// typedef ������������ (*���¶���ĺ���ָ����)(�����Ĳ�������1, �����Ĳ�������2, ...);
typedef void (*fun_ptr)(vector_int);

void printScore(vector_int);
void print_api(vector_int, fun_ptr);


int main() {

	vector_int score_vector{ 1, 2, 3, 4, 5 };

	fun_ptr ps_ptr = printScore;

	// ���ݺ���ָ��� print_api
	print_api(score_vector, ps_ptr);

	std::cout << "\n";
	// ���ݺ������� print_api
	print_api(score_vector, printScore);


	return 0;
}


void printScore(vector_int score_vector) {
	std::cout << "..in printScore, score list ::\t";
	for (my_int score : score_vector) {
		std::cout << score << "\t";
	}
}


void print_api(vector_int score_vector, fun_ptr input_fun) {
	input_fun(score_vector);
}



