/*

����һ��ѧ���࣬���� ���ԣ� ���������� �� ��Ϊ�����顢�ܲ���

3. ʹ�ó�ʼ���б�ķ�ʽ��ɶ�  ������ ����ĸ�ֵ������
4. ��main.cpp�зֱ�����ܲ��Ͷ���ĺ�������ӡ�������磺  18��������ڶ���...

*/



#include<iostream>

class Student {
private:
	std::string name;
	int age;


public:
	Student() : Student("unknown", 0) {}

	Student(std::string name, int age) : name(name), age(age) {
		std::cout << "..���ù��캯��...\n";
	}

	~Student() {
		std::cout << "..������������...\n";
	}

	void read() {
		std::cout << ".." << age << "��" << name << "�ڿ���...\n";
	}

	void run() {
		std::cout << ".." << age << "��" << name << "���ܲ�...\n";
	}

};


void createStudent(Student** stu, std::string name, int age) {	// ����Ϊָ��ָ���ָ��
	*stu = new Student("jacob", 18);			// ��ָ��ָ���ָ������ã��õ�ָ���д洢�ĵ�ַ�е�student�����
}


int main() {

	Student* stu;								// ����һ��ָ�� Student ������ָ��
	createStudent(&stu, "jacob", 18);			// �����ָ��ĵ�ַ����
	(*stu).read();								
	(*stu).run();
	delete stu;

	return 0;
}




/*

..���ù��캯��...
..18��jacob�ڿ���...
..18��jacob���ܲ�...
..������������...


*/