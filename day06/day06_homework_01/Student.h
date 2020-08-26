#pragma once

#include <iostream>
#include <vector>


class Student
{

public:

	std::string* name = nullptr;
	std::string id;
	std::vector<int> score_vector;

public:

	static std::string university;

	// �޲ι��캯��
	Student();

	// ȫ�ι��캯��
	Student(std::string name, std::string id, std::vector<int> score_vector);

	// ǳ�������캯������ֵ
	//Student(const Student& stu);

	// ������캯������ֵ
	Student(const Student& stu);

	// �ƶ����캯������ֵ
	Student(Student&& stu);

	// ��������
	~Student();

	// ���������<<
	friend std::ostream& operator<<(std::ostream& out, Student& stu);


};

