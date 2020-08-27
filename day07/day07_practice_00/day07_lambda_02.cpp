 /*
 
 practice_02: �����б�ʽ

 lambda �����ı��ʽ����������������

 [](�������� ������)->����ֵ����{}				// ���ص��Ǻ���ָ�룬��Ҫ����ָ����������գ���ֵ��

 []: �����б�
 {}: ������
 
 */


#include <iostream>

// һ�㺯����ʽ�Ա� lambda ����
int add(int a, int b) {
	return a + b;
}


/*

lambda ���������ֵ��÷�ʽ

*/
int main() {

	// auto �������� lambda ����ֵ
	auto add = [](int a, int b)->int {return a + b; };		// ���� auto result = [](int a, int b){return a + b;};
	int result = add(3, 4);
	std::cout << "result = " << result << "\n";

	// ����ָ�����
	int (*add_2)(int, int) = [](int a, int b) { return a + b; };
	int result2 = add_2(3, 4);
	std::cout << "result2 = " << result2 << "\n";


	// ֱ��lambda������С���Ÿ�ֵ���ؽ��
	int result3 = [](int a, int b) { return a + b; }(3, 4);
	std::cout << "result3 = " << result3 << "\n";

	// ������ auto
	auto result4 = [](int a, int b) { return a + b; }(3, 4);
	std::cout << "result4 = " << result4 << "\n";

	return 0;

}