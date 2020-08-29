#pragma once

#include <iostream>
#include <vector>


class Student
{

public:

	std::string* name = nullptr;
	std::string id;
	std::vector<int> score_vector;

	static std::string university;

	Student();
	Student(std::string name, std::string id, std::vector<int> score_vector);
	~Student();

	//Student() : Student("unknown", "00x", {}) {
	//	std::cout << "..log::无参构造...\n";
	//}

	//Student(std::string name, std::string id, std::vector<int> score_vector)
	//	: name{ new std::string{name} }
	//	, id{ id }
	//	, score_vector{ score_vector }{
	//	std::cout << "..log::有参构造...\n";
	//}

	//~Student() {
	//	std::cout << "..析构...\n";
	//	delete name;
	//}

};

