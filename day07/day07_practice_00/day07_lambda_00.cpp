 /*
 
 lambda �����ı��ʽ����������������

 [](�������� ������)->����ֵ����{}

 []: �����б�
 {}: ������
 
 */


#include <iostream>

// һ�㺯����ʽ�Ա� lambda ����
int add(int a, int b) {
	return a + b;
}


/*

lambda ����������д��

*/
int main() {

	std::cout << "..in day07_lambda_practice_00...\n";

	//��һ�֣�����д��
	[](int a, int b)->int {return a + b; };

	//�ڶ��֣��Զ��ƶϷ���ֵ���ͣ�ʡ�� "->��������"
	[](int a, int b) {return a + b; };

	//�����֣�û�в���
	[]() {std::cout << "hello ya" << std::endl; };

	//�����֣���Ȼû�в�������ʡ�� ()
	[] {std::cout << "hello ya" << std::endl; };



	return 0;

}