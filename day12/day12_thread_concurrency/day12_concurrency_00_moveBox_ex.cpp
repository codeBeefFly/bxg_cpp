/*

需求：

线程的同步练习 concurrency

举个例子，机器人的两只手臂同时从工作台上搬离积木，
完美的情况是前后交错执行，不会有空着手臂回去的情况，
但是有时也会发生一些特殊的情况，比如此时工作台上只剩下最后一块积木了，
两只手臂同时执行搬离的操作，此时就会有一只手臂空着回来了。多线程同步就是要解决这类问题。

为了解决这类多线程并发的问题，必须使用同步来处理。
在c++里面常用互斥量来处理线程的同步问题，除了互斥量之外，
还有使用`信号量`、`临界区`、`事件`等。


*/



#include <iostream>
#include <queue>
//#include <synchapi.h>
#include <Windows.h>
#include <thread>
#include <mutex>

using namespace std;



mutex m;    // 全局互斥锁
/*
 * 演示并发
 *      两只机械臂从工作台上搬走盒子
 */
class Box {};

//这是工作台
queue<Box> work_table;

//初始化工作台上有10个盒子
void init() {
    for (int i = 0; i < 10; ++i) {
        Box b;
        work_table.push(b);
    }
}

//盒子位于工作台上，所以盒子的移动功能，应该是由工作台来提供
//如果机械臂想要从工作台上搬走盒子，那么应该由手臂来调用工作台的移动函数。
//这实际上是一个面向对象的思想。
//void moveOut(string name) {
//    m.lock();
//    //cout << name << " 想要去搬运盒子 , 盒子的数量：" << work_table.size() << endl;
//    if (!work_table.empty()) { //false： 表示里面还有。  true :表示队列空了 没有盒子了。
//
//        Sleep(1);
//
//        work_table.pop(); // 搬走盒子
//
//        cout << name << " 搬走了一个盒子，还剩下：" << work_table.size() << endl;
//    }
//    //else if (work_table.empty()) {
//    //    std::cout << "盒子数目为：： 0，结束...\n";
//    //    m.unlock();
//    //    //exit(0);
//    //    //return;
//    //    //ExitThread;
//    //    abort();
//    //}
//    m.unlock();
//}


bool moveOut(string name) {
    m.lock();

    if (!work_table.empty()) {
        Sleep(1);
        work_table.pop();
        cout << name << " 搬走了一个盒子，还剩下：" << work_table.size() << endl;
        m.unlock();
        return true;
    }
    std::cout << name << " 正在操作，没有盒子了...\n";
    m.unlock();
    return false;
}

//左手臂
void leftHand() {
    //while (true) {
    //    moveOut("左手");
    //}
    while(moveOut("左手")){}
}

//右手臂
void rightHand() {
    //while (true) {
    //    moveOut("右手");
    //}
    while(moveOut("右手")){}
}


int main() {

    init();

    thread t1(leftHand);
    thread t2(rightHand);

    t1.join();
    t2.join();

    std::cout << "..finish...\n";

    return 0;
}


/*

output


左手 搬走了一个盒子，还剩下：9
左手 搬走了一个盒子，还剩下：8
左手 搬走了一个盒子，还剩下：7
左手 搬走了一个盒子，还剩下：6
左手 搬走了一个盒子，还剩下：5
右手 搬走了一个盒子，还剩下：4
左手 搬走了一个盒子，还剩下：3
左手 搬走了一个盒子，还剩下：2
右手 搬走了一个盒子，还剩下：1
左手 搬走了一个盒子，还剩下：0
右手 正在操作，没有盒子了...
左手 正在操作，没有盒子了...
..finish...




*/
