/*

����

����ģ�� + �ɱ����

����ͨ����һ�㣬����ģ��Ҳ�������أ��Ա����Ӧ�Ը��������


ģ�庯��������

 *      �ɱ������ ��������Ķ�䣨�ɶ���٣�
 *      ����ģ�壺��������͵Ķ�� (���Ϳ��Ա仯�����պܶ಻һ�������͡�)

*/


#include <iostream>
#include <iomanip>

using namespace std;

/*
 *  ģ����
 *      ģ�庯��������
 *
 *      ����ģ��������ǿ���Ӧ�Բ�ͬ�Ĳ����������Լ�������˳��仯�ġ�
 *      ����������������Ͷ�һ����Ψ��ֻ�в����ĸ����ڱ仯�� ��ô���Կ���ʹ��
 *      �ɱ��������������ģ�塣
 *
 *      �ɱ������ ��������Ķ�䣨�ɶ���٣�
 *      ����ģ�壺��������͵Ķ�� (���Ϳ��Ա仯�����պܶ಻һ�������͡�)
 *
 */
 /*

 int add(int a , int b ){
     return a + b;
 }
 */

template <typename  T>
T add(T a, T b) {
    return a + b;
}

template <typename  T>
T add(T a, T b, T c) {
    return a + b + c;
}

template <typename  T>
T add(T a, T b, T c, T d) {
    return a + b + c;
}



int main() {

    cout << add(3, 4) << endl;
    cout << add(3.5, 4.5) << endl;


    return 0;
}

/*

output


7
8

*/
