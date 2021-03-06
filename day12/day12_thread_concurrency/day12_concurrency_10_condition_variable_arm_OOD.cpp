#include <iostream>
//#include <synchapi.h>
#include <Windows.h>
#include <thread>
#include <queue>
#include <condition_variable>

using namespace std;

/*
 * 面向对象 + 条件变量 解决搬运盒子
 */

class Box {};

class WorkTable {
    mutex m;
    condition_variable cv;
    queue<Box> q;
public:
    WorkTable() {
        for (int i = 0; i < 5; ++i) {
            Box b;
            q.push(b);
        }
    }

    //工作台上，有搬进来盒子，也有搬出去盒子。

    //把盒子搬进来。
    void moveIn() {
        Box b;
        q.push(b);


        cout << "左手搬上来了一只盒子，总数：" << q.size() << endl;

        cv.notify_all();
        Sleep(3000);
    }

    //把盒子搬走
    void moveOut() {
        unique_lock<mutex> ul(m);


        ////如果工作台有盒子，则不进入等待状态。
        //如果lambda表达式返回true， 则跳过等待。
        //如果lambda表达式返回false ，则进入等待。

        cv.wait(ul, [&] {
            cout << "进去状态的判定，如果队列为空，则等待。" << endl;
            return q.size() > 0;
            });

        q.pop();
        cout << "右手搬走了一只盒子，还剩：" << q.size() << endl;
        Sleep(500);

        /* if(!q.empty()){
             q.pop();
             cout <<"右手搬走了一只盒子，还剩：" << q.size() <<endl;
             Sleep(500);
         }else{
             cout << "工作台为空，继续下一次搬运" <<endl;
             cv.wait(ul);
         }*/
    }
};

class leftHand {

    WorkTable* wt;                          // 自定义类成员变量
public:
    leftHand(WorkTable* wt) : wt(wt) {}     // 使用类成员变量初始化

    void moveIn() {

        while (true) {
            wt->moveIn();
        }
    }

};

class rightHand {

    WorkTable* wt;
public:
    rightHand(WorkTable* wt) : wt(wt) {}

    void moveOut() {
        while (true) {
            wt->moveOut();
        }
    }
};


int main() {


    WorkTable wt;

    leftHand left(&wt);
    rightHand right(&wt);

    //thread t1(bind(&leftHand::moveIn, left));
    //thread t2(bind(&rightHand::moveOut, right));
    thread t1(&leftHand::moveIn, left);
    thread t2(&rightHand::moveOut, right);



    t1.join();
    t2.join();

    return 0;
}


/*

output:

左手搬上来了一只盒子，总数：进去状态的判定，如果队列为空，则等待。6

右手搬走了一只盒子，还剩：5
进去状态的判定，如果队列为空，则等待。
右手搬走了一只盒子，还剩：4
进去状态的判定，如果队列为空，则等待。
右手搬走了一只盒子，还剩：3
进去状态的判定，如果队列为空，则等待。
右手搬走了一只盒子，还剩：2
进去状态的判定，如果队列为空，则等待。
右手搬走了一只盒子，还剩：1
进去状态的判定，如果队列为空，则等待。
右手搬走了一只盒子，还剩：0
左手搬上来了一只盒子，总数：1
进去状态的判定，如果队列为空，则等待。
右手搬走了一只盒子，还剩：0
进去状态的判定，如果队列为空，则等待。
左手搬上来了一只盒子，总数：1
进去状态的判定，如果队列为空，则等待。
右手搬走了一只盒子，还剩：0
进去状态的判定，如果队列为空，则等待。
左手搬上来了一只盒子，总数：1
进去状态的判定，如果队列为空，则等待。
右手搬走了一只盒子，还剩：0
进去状态的判定，如果队列为空，则等待。
左手搬上来了一只盒子，总数：1
进去状态的判定，如果队列为空，则等待。
右手搬走了一只盒子，还剩：0
进去状态的判定，如果队列为空，则等待。
左手搬上来了一只盒子，总数：1
进去状态的判定，如果队列为空，则等待。
右手搬走了一只盒子，还剩：0
进去状态的判定，如果队列为空，则等待。
左手搬上来了一只盒子，总数：1
进去状态的判定，如果队列为空，则等待。
右手搬走了一只盒子，还剩：0
进去状态的判定，如果队列为空，则等待。
左手搬上来了一只盒子，总数：1
进去状态的判定，如果队列为空，则等待。
右手搬走了一只盒子，还剩：0
进去状态的判定，如果队列为空，则等待。
左手搬上来了一只盒子，总数：1
进去状态的判定，如果队列为空，则等待。
右手搬走了一只盒子，还剩：0
进去状态的判定，如果队列为空，则等待。
左手搬上来了一只盒子，总数：1
进去状态的判定，如果队列为空，则等待。
右手搬走了一只盒子，还剩：0
进去状态的判定，如果队列为空，则等待。
左手搬上来了一只盒子，总数：1
进去状态的判定，如果队列为空，则等待。
右手搬走了一只盒子，还剩：0
进去状态的判定，如果队列为空，则等待。
左手搬上来了一只盒子，总数：1
进去状态的判定，如果队列为空，则等待。
右手搬走了一只盒子，还剩：0
进去状态的判定，如果队列为空，则等待。
左手搬上来了一只盒子，总数：1
进去状态的判定，如果队列为空，则等待。
右手搬走了一只盒子，还剩：0
进去状态的判定，如果队列为空，则等待。
左手搬上来了一只盒子，总数：1
进去状态的判定，如果队列为空，则等待。
右手搬走了一只盒子，还剩：0
进去状态的判定，如果队列为空，则等待。
左手搬上来了一只盒子，总数：1
进去状态的判定，如果队列为空，则等待。
右手搬走了一只盒子，还剩：0
进去状态的判定，如果队列为空，则等待。
左手搬上来了一只盒子，总数：1
进去状态的判定，如果队列为空，则等待。
右手搬走了一只盒子，还剩：0
进去状态的判定，如果队列为空，则等待。
左手搬上来了一只盒子，总数：1
进去状态的判定，如果队列为空，则等待。
右手搬走了一只盒子，还剩：0
进去状态的判定，如果队列为空，则等待。
左手搬上来了一只盒子，总数：1
进去状态的判定，如果队列为空，则等待。
右手搬走了一只盒子，还剩：0
进去状态的判定，如果队列为空，则等待。
左手搬上来了一只盒子，总数：1
进去状态的判定，如果队列为空，则等待。
右手搬走了一只盒子，还剩：0
进去状态的判定，如果队列为空，则等待。
左手搬上来了一只盒子，总数：1
进去状态的判定，如果队列为空，则等待。
右手搬走了一只盒子，还剩：0
进去状态的判定，如果队列为空，则等待。
左


*/