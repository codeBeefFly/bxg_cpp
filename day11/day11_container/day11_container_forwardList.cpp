/*

����

��ϰ forward_list �����б�


forward_list ��������ֻ֧�ֵ���˳����ʣ������ɾ���죬��ѯ�͸�����

*/


#include <iostream>
#include <forward_list>
#include <list>
#include <vector>

using namespace std;


/*
 * forward_list
 *
 *      //�ص�һ�� ��ѯ���޸ıȽ��� û���±�
 *      //�ص�� �������ɾ���ȽϿ�
 *
 */

 //typedef :�Ѿ�֪�������Ƶ��򵥵����ơ�
 //typedef typename vector::iterator iterator;
int main() {


    vector<int>::iterator vi;

    forward_list<int> flist{ 3,4,5 };

    //׷��Ԫ��
    flist.push_front(6);

    //�ص�һ�� ��ѯ���޸ıȽ��� û���±꣬ʹ�õ����� .begin() end() ����
    //flist.assign(0 , 88);
    for (auto i = flist.begin(); i != flist.end(); i++) {
        if (*i == 4) {
            *i = 44;
        }
    }

    for (auto i = flist.begin(); i != flist.end(); i++) {
        cout << " i = " << *i << endl;
    }


    //�ص�� �������ɾ���ȽϿ�

    flist.remove(44);


    for (auto i = flist.begin(); i != flist.end(); i++) {
        cout << " i = " << *i << endl;
    }



    return 0;
}


/*

output

 i = 6
 i = 3
 i = 44
 i = 5
 i = 6
 i = 3
 i = 5

*/
