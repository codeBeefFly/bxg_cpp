/*
����

����ָ�����ϰ

��һ��vectorָ�룬 ���ڴ洢3��ѧ�����������ġ����壬 
��vector��ָ�봴����������createContainer ������������
���Ҹú���û�з���ֵ��ͨ�����������ķ�ʽ���������ⲿvectorָ�롣

*/

#include <iostream>
#include <vector>


struct student {
	std::string name;
};


void createContainer(std::vector<student> ** student_vector);


int main() {
	std::cout << "..in vector_pointer...\n";

	std::vector<student> * student_vector;

	createContainer(&student_vector);
	
	student stu_a;
	stu_a.name = "jacob";

	student stu_b;
	stu_b.name = "raptor";

	student stu_c;
	stu_c.name = "king";


	(*student_vector).push_back(stu_a);
	(*student_vector).push_back(stu_b);
	(*student_vector).push_back(stu_c);


	// ��ӡ
	for (student s : (*student_vector)) {
		std::cout << "..student name :: " << s.name << "\t";
	}


	return 0;
}


void createContainer(std::vector<student> ** student_vector) {

	*student_vector = new std::vector<student>;

}