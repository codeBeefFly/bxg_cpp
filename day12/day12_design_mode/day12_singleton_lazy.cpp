/*

����

����ģʽ


*/


#include <iostream>

using namespace std;

/*
 * ����ģʽ
 *     ����ʽ
 *          �ڻ�û��ȥ��ȡ����֮ǰ�����Ѿ������ö����ˡ�
 *
 *     1. ��ֹ���˴���ʵ��  ---> ����˽��
 *
 *     2. �Լ�Ҫ����ʵ��
 *
 *     3. ���Լ������õ�ʵ����¶��ȥ��������ʹ�á�  ��̬��Ա������
 *
 *    c++ ����ĵ������Ƿ���ָ�롣
 */


class bank {
private:
    //1. ����˽�С�  �����˼Ҵ�������
    bank() {
        cout << "����bank����" << endl;
    }
public:
    //2. �Լ�����ʵ��
    static  bank* b;  //�Լ�����

    //3. �Ѵ����õ�ʵ������ȥ��
    static bank* getInstance() {
        return  b;
    }
};

bank* bank::b = new bank();

int main() {



    cout << "main��ʼ��~~" << endl;
    bank* b1 = bank::getInstance();
    bank* b2 = bank::getInstance();

    cout << "b1�ĵ�ַ : " << b1 << endl;
    cout << "b2�ĵ�ַ : " << b2 << endl;




    return 0;
}

/*

output

����bank����
main��ʼ��~~
b1�ĵ�ַ : 00000210D3AB5100
b2�ĵ�ַ : 00000210D3AB5100

*/