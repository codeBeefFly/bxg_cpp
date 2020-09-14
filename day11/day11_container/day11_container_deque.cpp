/*

����
��ϰ deque ˫�˶���

*/


#include <iostream>
#include <deque>
#include <queue>

using namespace std;


/*
 * dequeue
 */

int main() {

    //����һ������
    deque<int> que{ 3,4,5 };

    //���
    que.push_back(6);
    que.push_front(2);

    //�޸�
    que[0] = 22;

    //ȡֵ
    cout << que[0] << endl;

    //ɾ��
    que.erase(que.begin());

    //����
    for (int i : que) {
        cout << "i = " << i << endl;
    }

    return 0;
}


/*

output:

22
i = 3
i = 4
i = 5
i = 6


*/