#include <iostream>
#include <vector>

using namespace std;


/*
 * ������
 */

int main() {


    vector<int> vi{ 10,20,30,40 };

    /* template<typename _Iterator, typename _Container>
     class __normal_iterator*/

     //STL ��Դ���һ�¡�  vector

    //__gnu_cxx::__normal_iterator<int*, vector<int>>  it = vi.begin();

    //vector Ҳ��һ���ࡣ
    //���������ʵ����Ҳ��һ���ࡣ  ��������vector�����Ԫ�ص�ʱ��
    //�ײ�| �ڲ����õ������������ǵ�Ԫ�ؽ��й�����
    auto  iterator = vi.begin();

    //������õ�������� *_M_current;  _M_current �������ǵ�Ԫ�ض�Ӧ��ָ������

    //���vector�����ŵ���int���͵����ݣ� ��ô_M_current ���� int*
    // ����Ե�����ʹ��*���ţ�������Ƕ� _M_current ʹ�ý����á�
    cout << "iterator = " << *iterator << endl;
    //cout << "base() = " << *iterator.base() << endl;    // û�� base ������� no member base

    cout << *(vi.begin() + 1) << endl;


    return 0;
}

/*

output

iterator = 10
20

*/