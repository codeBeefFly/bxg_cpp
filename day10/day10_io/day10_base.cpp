/*

����

�˽� ����������÷�

*/


#include <iostream>
//#include <memory>
//#include <vector>
using  namespace std;
/*
 * �������
 */
int main() {

    //1. ���bool
    bool flag = false;
    bool flag2 = true;
    cout << boolalpha << "flag = " << flag << endl;  //��ӡtrue | false;
    cout << noboolalpha << "flag2 = " << flag2 << endl; //���ɴ�ӡ 1 | 0

    //2. ���ʮ���� �� �˽��ơ�ʮ������
    int num = 2309;

    cout << showbase << "ʮ���� : " << dec << num << endl;  // 9
    cout << "�˽��� : " << oct << num << endl; // A 11
    cout << "ʮ������ : " << hex << num << endl; // B 9
    cout << noshowbase;

    cout << dec << 18 << endl;


    return 0;
}


/*

flag = false
flag2 = 1
ʮ���� : 2309
�˽��� : 04405
ʮ������ : 0x905
18

*/
