#include <iostream>
#include <memory>
#include <vector>
using  namespace std;

/*
 *���׳��쳣�Ĵ���
 *
 */

 //�ٸ����ӣ�������������ǿ����ģ�������˵��á�
 /*
  * �������������  ����һ /  ������
  * ע�⣺ ������������ݵ���0 ����ô���򽫻�ֱ��ֹͣ
  *      ������������Ƿ��ش���Ĵ��� 500.
  */
int  calc_div(int a, int b) {
    if (b == 0) {
        //1. ֱ����ֹ����
       // exit(0);
       //abort();

       //2. ���ش���Ĵ��롣
        return 500;
    }
    return a / b;
}


int main() {

    calc_div(5, 0);
    cout << calc_div(4, 2) << endl;
    cout << calc_div(4, 0) << endl;

    cout << "��������ӡ�����" << endl;


    return 0;
}


/*

output


2
500
��������ӡ�����

*/
