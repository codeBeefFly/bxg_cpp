/*

Ŀ�ģ�
ʹ�ú���ָ�룬���� printScore()����

����
1. ���� vector<int>
2. �ͻ�������ͬ���ܵĴ�ӡ���� printScore_0(vector<int>), printScore_1(vector<int>);
3. ����Ա�ṩ�Ĵ�ӡ�ӿ� print_api(vector<int>, (*print_ptr)(vector<int>))
4. ����һ����ں���
5. д�� prototype + ��ں��� + ����������ʽ


�βΣ��ں��������г���
ʵ�Σ��ں��������г���

*/


#include<iostream>
#include<vector>


// �ͻ��˴�ӡ����
void printScore_0(std::vector<int>);
void printScore_1(std::vector<int>);
void printScore_2(std::vector<int>);


// �����ṩ�Ĵ�ӡapi
void print_api(std::vector<int>, void (*print_ptr)(std::vector<int>));


int main() {
	
	std::vector<int> scores{ 1, 2, 3, 4, 5, 6 };

	// �ͻ�0ʹ�����ǵķ���ʹ�ó���api��ӡ
	print_api(scores, printScore_0);

	// �ͻ�1ʹ�����ǵķ���ʹ�ó���api��ӡ
	print_api(scores, printScore_1);


	// �ͻ�2ʹ�����ǵķ���ʹ�ó���api��ӡ
	print_api(scores, printScore_2);

	return 0;
}


void printScore_0(std::vector<int> score_vector) {
	std::cout << "\n..in printScore_0...\n"
		<< "..scores ::\t";
	for (int score : score_vector) {
		std::cout << score << "\t";
	}
}


void printScore_1(std::vector<int> score_vector) {
	std::cout << "\n..in printScore_1...\n"
		<< "..scores ::\t";
	for (int score : score_vector) {
		std::cout << score << "\t";
	}
}


void printScore_2(std::vector<int> score_vector) {
	std::cout << "\n..in printScore_2...\n"
		<< "..scores ::\t";
	// ʹ���±��ӡ
	for (int i = 0; i < score_vector.size(); i++) {
		std::cout << score_vector[i] << "\t";
	}
}


void print_api(std::vector<int> score_vector, void (*print_fun_ptr)(std::vector<int>)) {
	print_fun_ptr(score_vector);
}