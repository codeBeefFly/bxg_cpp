#include <iostream>
//#include <synchapi.h>
#include <Windows.h>
#include <thread>
#include <queue>
#include <condition_variable>

using namespace std;

/*
 * 左手臂每隔3秒钟，可以搬过来一个盒子，右手臂每隔1秒钟可以搬走一个盒子。
 * 如果工作台上没有了盒子，那么右手臂应该要进入休眠的状态，
 * 虽然休眠可以降低右手臂轮询队列的次数，但是仍然无法达到最优
 *
 * 使用条件变量来解决。
 */

class Box {};

queue<Box> q;

mutex m;

condition_variable cv;

void init() {
    for (int i = 0; i < 10; ++i) {
        Box b;
        q.push(b);
    }
}

void leftHand() {
    while (true) {

        // lock_guard<mutex> lg(m);

        Box b;
        q.push(b);

        //只要左手搬上来一个盒子，就马上通知右手
        cv.notify_all();            // 一定要先通知，再执行吗
        unique_lock<mutex> ul(m);   // 唯一锁，有 lock_guard 所有功能并且可以手动释放锁
        cout << "左手搬过来一个盒子，工作台的盒子数量：" << q.size() << endl;
        ul.unlock();
        Sleep(3000);
    }
}


void rightHand() {
    while (true) {

        unique_lock<mutex> ul(m);
        //右手去工作台搬盒子，如果工作台是空的，那么右手应该进入等待状态。
        if (q.empty()) {
            cout << "工作台为空，右手进入等待状态" << endl;
            cv.wait(ul);
        }

        //如果不是空就要搬盒子
        q.pop();
        cout << "右手搬走了一个盒子，还剩： " << q.size() << endl;

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
