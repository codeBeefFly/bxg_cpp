/*

����

�ɱ��������ģ�������

ʡ�Ժŵķ�ʽ


Ҫ����ʡ�Ժŷ�ʽ�Ŀɱ������
ʹ���ĸ���ĺ�`va_start`��`va_arg`��`va_end` �� `va_list`

����ͷ�ļ� <cstdarg>


��һ��

*/


#include <iostream>
#include <cstdarg>
#include <iomanip>


int add(int count, ...) {	// count���ɱ��������
	
	va_list vaList;

	va_start(vaList, count);

	int sum{ 0 };
	for (int i = 0; i < count; i++) {
	
		//// ��ӡ����
		//int result = va_arg(vaList, int);	// ÿһ����list��ȡ��һ��ֵ���൱�� pop
		//std::cout << "...����ֵΪ::\t" << result << "\n";

		// �����ܺ�
		sum += va_arg(vaList, int);

	}



	va_end(vaList);			// ������

	return sum;

}


int main() {

	std::cout << "..in template_03...\n";

	std::cout << add(5, 1, 2, 3, 4, 5) << "\n";

	return 0;
	
}



