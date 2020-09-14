#include <iostream>
#include <string>
#include <set>

using namespace std;
/*
 * �������� - set
 *      set ����������һ�����������������װ��������Щ����
 *      ������ר�ŵı�ǩ  �� �±�����Ӧ�����ǣ� ����Ҫ���ҵ�����һ������
 *      ����ȥ�޸ĵ�����ָ��������û�С�
 *
 *      set����Ҫ�����������洢���ظ������ݡ� ���ݵ�Ψһ
 */

int main() {

    //1. �������� , ���ҳ�ʼ�����ݡ�
    set<int> s({ 3,4,5 });

    //2. �������
    s.insert(6);
    s.insert(6);  //�ظ������ݷŲ���ȥ��

    //3.���
    s.erase(5);

    //4. ����  �� ���������Ƿ���������� ��
    cout << "�ܳ��ȣ�" << s.size() << endl;
    cout << "��û��8��" << s.count(8) << endl;


    for (int val : s) {
        cout << "val = " << val << endl;
    }




    return 0;
}

/*

output

�ܳ��ȣ�3
��û��8��0
val = 3
val = 4
val = 6


*/
