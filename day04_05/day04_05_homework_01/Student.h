#pragma once

#include <iostream>
#include <vector>

class Student
{
public:
	std::string* name = nullptr;
	std::vector<int> score_vector;

	Student();
	Student(std::string* name);
	Student(std::string* name, std::vector<int> score_vector);	// ����ʲô����

	//�������캯����д�����
	Student(const Student& stu);

	//void putScore(std::vector<int> score_vector);

	// һ����λ��ͨ�����캯���ķ�ʽ������ѧ��

	//void updateScore(std::vector<int> score_vector);
	void updateScore(void (*score_fun)());
	//void showInfo(std::vector<int> score_vector);
	void showInfo();

private:
	void update2Sixty_default();

};

