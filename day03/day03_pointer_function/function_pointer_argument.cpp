/*

���԰�ĳ������Aͨ�������ķ�ʽ���ݸ���һ������B��
����ں���B����ִ�д��ݽ����ĺ���A��������Ȼ����ֱ����Ϊ���������д��ݣ�
���Ǻ���ָ����ԡ�ʵ�����ڴ��ݵ�ʱ�򣬴��ݵ���ָ����ѡ�

Ҫ������һ������ָ�룬ֻ��Ҫʹ��`ָ��`���滻`������`���ɡ�


�βΣ��ں��������г���
ʵ�Σ��ں��������г���

*/

// ����һ����Ҫ�������������ݵĺ���
#include <iostream>


int add(int a, int b);
// ����һ�����к���ָ��ĺ���
int calc(int a, int b, int (*fun_ptr)(int, int));


// ����һ���ӿں���
int main() {
	
	// ����һ������ָ��
	int (*add_fun_ptr)(int, int) = add;
	std::cout << "..enter a and b for addition ::\t";
	int a, b;
	std::cin >> a >> b;
	
	// ��һ�ֺ���ָ����Ϊ�����ķ���������һ������ָ�룬�ڴ����������ָ��Ľ����ã�Ҳ���Ǵ�����������ĵ�ַ
	std::cout << "..result_01 is " << a << " + " << b << " = " << calc(a, b, add_fun_ptr) << "\n";	// ������Ҫ�������ĵ�ַ��Ҳ���Ǻ���ָ��Ľ�����

	// �ڶ��к���ָ����Ϊ�����ķ�����ֱ�Ӵ�������������ƣ���Ϊ�������ƾ��Ǻ����ĵ�ַ���൱�ں���ָ��Ľ�����
	std::cout << "..result_02 is " << a << " + " << b << " = " << calc(a, b, add) << "\n";	


	return 0;
}


// ���屻�����������ݵĺ���
int add(int a, int b) {
	return a + b;
}


// ���庬�к���ָ��ĺ���
// a, b �β���Ϊ����ָ����β� 
int calc(int a, int b, int (*fun_ptr)(int, int)) {
	return fun_ptr(a, b);
}
