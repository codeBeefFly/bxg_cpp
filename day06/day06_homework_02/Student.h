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
	//	std::cout << "..log::�޲ι���...\n";
	//}

	//Student(std::string name, std::string id, std::vector<int> score_vector)
	//	: name{ new std::string{name} }
	//	, id{ id }
	//	, score_vector{ score_vector }{
	//	std::cout << "..log::�вι���...\n";
	//}

	//~Student() {
	//	std::cout << "..����...\n";
	//	delete name;
	//}

};

