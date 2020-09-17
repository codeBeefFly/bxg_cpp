#include <iostream>
//#include <synchapi.h>
#include <Windows.h>
#include <thread>
#include <queue>


using namespace std;

/*
 * 左手臂每隔3秒钟，可以搬过来一个盒子，右手臂每隔1秒钟可以搬走一个盒子。
 * 如果工作台上没有了盒子，那么右手臂应该要进入休眠的状态，
 * 虽然休眠可以降低右手臂轮询队列的次数，但是仍然无法达到最优
 */

class Box {};

queue<Box> q;

void init() {
    for (int i = 0; i < 10; ++i) {
        Box b;
        q.push(b);
    }
}

void leftHand() {
    while (true) {
        Box b;
        q.push(b);

        cout << "左手搬过来一个盒子，工作台的盒子数量：" << q.size() << endl;
        Sleep(3000);
    }
}


void rightHand() {
    while (true) {

        if (q.empty()) {
            cout << "右手想去搬运盒子， 工作台上的数量为 0 " << endl;
            Sleep(1000);
            continue;
        }
        //不为空
        q.pop();
        cout << "右手搬走一个盒子，剩余数量：" << q.size() << endl;
        Sleep(1000);
    }
}



int main() {

    init();

    thread t1(leftHand);
    thread t2(rightHand);


    t1.join();
    t2.join();

    return 0;
}

/*

右手搬走一个盒子，剩余数量：左手搬过来一个盒子，工作台的盒子数量：109

右手搬走一个盒子，剩余数量：9
右手搬走一个盒子，剩余数量：8
左手搬过来一个盒子，工作台的盒子数量：9
右手搬走一个盒子，剩余数量：8
右手搬走一个盒子，剩余数量：7
右手搬走一个盒子，剩余数量：6
左手搬过来一个盒子，工作台的盒子数量：7
右手搬走一个盒子，剩余数量：6
右手搬走一个盒子，剩余数量：5
右手搬走一个盒子，剩余数量：4
左手搬过来一个盒子，工作台的盒子数量：5
右手搬走一个盒子，剩余数量：4
右手搬走一个盒子，剩余数量：3
右手搬走一个盒子，剩余数量：2
左手搬过来一个盒子，工作台的盒子数量：3
右手搬走一个盒子，剩余数量：2
右手搬走一个盒子，剩余数量：1
右手搬走一个盒子，剩余数量：0
左手搬过来一个盒子，工作台的盒子数量：1
右手搬走一个盒子，剩余数量：0
右手想去搬运盒子， 工作台上的数量为 0
右手想去搬运盒子， 工作台上的数量为 0
左手搬过来一个盒子，工作台的盒子数量：1
右手搬走一个盒子，剩余数量：0
右手想去搬运盒子， 工作台上的数量为 0
右手想去搬运盒子， 工作台上的数量为 0
左手搬过来一个盒子，工作台的盒子数量：1
右手搬走一个盒子，剩余数量：0
右手想去搬运盒子， 工作台上的数量为 0
右手想去搬运盒子， 工作台上的数量为 0
左手搬过来一个盒子，工作台的盒子数量：1
右手搬走一个盒子，剩余数量：0

*/