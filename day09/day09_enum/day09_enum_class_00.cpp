/*

����

��ϰ �޶��������ö�� class + ���޶�������ö��

�﷨��
enum class ö������ { ö����1, ö����2, ... }



 * ö��
 *      enum ,
 *      0. �޶�������  enum class ö�ٵ����� { ö����1 , ö����2 ... }
 *      1. ö�������ÿһ��ö��������Ӧ��һ�����֣�������ִ�0 ��ʼ��
 *      2. ���޶���Χ�����ʱ����Ҫ�ֶ�ǿת����
 *      3. �޶���Χ�Ͳ��޶���Χ��д����ʲô����
 

*/


#include <iostream>


enum class Color	// �޶�������ö��
{
	RED,
	GREEN,
	YELLO
};


enum Color_Small
{

	S_RED,
	S_GREEN,
	S_YELLO,

};



int main() {

	{
		std::cout << (int)Color::RED << "\n";
		std::cout << (int)Color::GREEN << "\n";
		std::cout << (int)Color::YELLO << "\n";

		// ����
		//std::cout << Color::RED << "\n";
		//std::cout << Color::GREEN << "\n";
		//std::cout << Color::YELLO << "\n";
	}

	{
		std::cout << S_RED << "\n";
		std::cout << S_GREEN << "\n";
		std::cout << S_YELLO << "\n";
	}


	return 0;
}


/*

output


0
1
2

0
1
2

*/