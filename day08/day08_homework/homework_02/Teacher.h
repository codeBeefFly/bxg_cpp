#pragma once

#include <iostream>


class Teacher
{

private:

	friend std::istream& operator>>(std::istream& in , Teacher& teacher);
	friend std::ostream& operator<<(std::ostream& out, Teacher& teacher);

public:
	
	std::string name;
	int age;
	std::string subject;

	Teacher();
	Teacher(std::string name, int age, std::string subject);
	~Teacher();

};

