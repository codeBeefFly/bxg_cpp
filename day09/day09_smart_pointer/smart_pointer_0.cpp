/*

����

����ָ�� 

Ψһָ��   unique_ptr

���ܿ�����ֻ���ƶ�

*/


#include <iostream>
#include <memory>


int main() {

	std::cout << "..in smart_pointer_0...\n";

	// ��ָͨ����
	int a = 3;
	int* p = &a;


	// ����һ��Ψһָ�����ָ���������� int
	// ʹ���޲ι��죬�޷�����ָ�룬class unique_ptr Ψһָ����һ���� 
	std::unique_ptr<int> u_ptr;

	// �����вι��죬����ָ�� 
	//std::unique_ptr<int> u_ptr2(p);	// ����д�ᱨ��
	//std::unique_ptr<int> u_ptr2(p, );	  // ��θ�
	//std::unique_ptr<int> u_ptr2(std::move(p));	// ����дҲ����
	//std::unique_ptr<int> u_ptr2 = std::move(p);	// ����Ҳ����  ��ȫû�㶮

	// �����вι��죬������ڴ�ָ��
	std::unique_ptr<int> u_ptr3(new int(3));



	return 0;
}