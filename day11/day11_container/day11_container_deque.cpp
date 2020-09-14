/*

需求：
练习 deque 双端队列

*/


#include <iostream>
#include <deque>
#include <queue>

using namespace std;


/*
 * dequeue
 */

int main() {

    //声明一个队列
    deque<int> que{ 3,4,5 };

    //添加
    que.push_back(6);
    que.push_front(2);

    //修改
    que[0] = 22;

    //取值
    cout << que[0] << endl;

    //删除
    que.erase(que.begin());

    //遍历
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