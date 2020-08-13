/*
有一个int类型数组，存储着张三的6个学科成绩，其中有的学科成绩不及格，
现在想使用updateScore() 函数来更新不及格的分数为100分。
updateScore (int count  , int [] scores)  
count : 为数组的长度，  
scores 用于接收数组。 
在函数内部使用指针运算，修改分数。
*/

#include<iostream>


int updateScore(int count, int scores[]);	//传递数组+数组长度
int printScore(int count, int scores[]);	//传递数组+数组长度


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


int updateScore(int count, int scores[]) {	//数组传递的是地址
	
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