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

	// 无参构造函数
	Student();

	// 全参构造函数
	Student(std::string name, std::string id, std::vector<int> score_vector);

	// 浅拷贝构造函数，左值
	//Student(const Student& stu);

	// 深拷贝构造函数，左值
	Student(const Student& stu);

	// 移动构造函数，右值
	Student(Student&& stu);

	// 析构函数
	~Student();

	// 重载运算符<<
	friend std::ostream& operator<<(std::ostream& out, Student& stu);


};

