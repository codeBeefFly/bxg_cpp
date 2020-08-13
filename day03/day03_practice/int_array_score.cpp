/*
��һ��int�������飬�洢��������6��ѧ�Ƴɼ��������е�ѧ�Ƴɼ�������
������ʹ��updateScore() ���������²�����ķ���Ϊ100�֡�
updateScore (int count  , int [] scores)  
count : Ϊ����ĳ��ȣ�  
scores ���ڽ������顣 
�ں����ڲ�ʹ��ָ�����㣬�޸ķ�����
*/

#include<iostream>


int updateScore(int count, int scores[]);	//��������+���鳤��
int printScore(int count, int scores[]);	//��������+���鳤��


int main(){
	std::cout << "..in int_array_score...\n";
	
	int scores[]{ 70, 50, 65, 20, 100, 79 };

	printScore(6, scores);
	std::cout << "\n";

	updateScore(6, scores);

	printScore(6, scores);
	std::cout << "\n";
	
	return 0;
}


int updateScore(int count, int scores[]) {	//���鴫�ݵ��ǵ�ַ
	
	for (int i = 0; i < count; i++) {
		if (*(scores + i) < 60) {
			*(scores + i) = 60;
		}
	}

	return 0;
}


int printScore(int count, int scores[]) {

	for (int i = 0; i < count; i++) {
		std::cout << *(scores + i) << "\t";
	}

	return 0;
}