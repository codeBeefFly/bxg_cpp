/*

����

����������˳�������кܴ�Ĳ�ͬ��
˳��������Ԫ��������������˳��ģ���������Ⱥ���㣩 �� 
���������������ƽ�˳��ĸ����Ϊ�����ǰ��չؼ���������Ԫ�صġ�
C++�г��õĹ���������������`map` �� `set` , 
map �е����� python �����`�ֵ�`��ʹ�ü�ֵ�Ե���ʽ���洢


pair������ͷ�ļ�`#include ` �У�һ��pair�����������ݳ�Ա��������ģ�壬
�����ڴ��������ʱ����Ҫ��ӷ��Ͳ�������������ʾ��������������͡�

*/


#include <iostream>
#include <string>
//#include <utility>

using namespace std;
/*
 * �������� - map
 *      �洢���Ǽ�ֵ�ԡ�  key - value
 *      c++ ��һ����������װ��ֵ��   pair
 */

int main() {

    pair<string, int> p1("����", 100);
    cout << p1.first << " : " << p1.second << endl;

    pair<string, int> p2("����", 50);
    cout << p2.first << " : " << p2.second << endl;


    return 0;
}


/*

output


���� : 100
���� : 50


*/