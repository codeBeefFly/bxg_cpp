#include <iostream>
#include <memory>
using  namespace std;

/*
 * Ψһָ��
 *  unique_ptr;
 */
int main() {
    int a = 3;
    int* p = &a;
    int* p2 = new int(3);

    // ����һ��ֻ��ָ��Ķ��� ����ָ������������� int
    //�޲ι��졣  û�й���ָ��
    unique_ptr<int>  uq;

    //���������вι���  ������һ��ָ�� p
    //unique_ptr<int> uq2(p);     // ��� 

    //��ν������ָ�룬��ʵ������һ���࣬��������������ָ�롣
    //����ָ����ͷţ�����������ɡ� ������ڴ��ָ�롣
    unique_ptr<int> uq3(new int(3));



    return 0;
}
