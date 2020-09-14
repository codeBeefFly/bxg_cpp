#include <iostream>
#include <queue>
//#include <synchapi.h>
#include <Windows.h>
#include <thread>
#include <mutex>
#include <functional>

using namespace std;



/*
 * 演示并发  - 使用面向对象来包装代码
 *      两只机械臂从工作台上搬走盒子 ， 工作台上初始有10个盒子。
 */

 //盒子类
class Box {};

//工作台类
class worktable {

    mutex m; //互斥量 |互斥元
    queue<Box> q;
public:
    worktable() {
        for (int i = 0; i < 10; ++i) {
            Box b;
            q.push(b);
        }
    }

    int moveOut(string name) {
        m.lock();
        if (!q.empty()) {
            Sleep(500);

            q.pop();

            cout << name << " 搬走了一个盒子 ， 还剩下：" << q.size() << endl;

            // m.unlock();
            m.unlock();
            return 1;
        }
        m.unlock();
        return 0;
    }


    ~worktable() {
        cout << "工作台销毁了" << endl;
    }

};

//手臂类
class hand {

    string name;

    //还要知道去哪里搬运。
    worktable* wt;
public:
    hand() {}
    hand(worktable* wt, string name) : wt(wt), name(name) {}

    void moveBox() {
        while (true) {
            int code = wt->moveOut(name);
            if (code == 0) break;
        }
    }

    ~hand() {}

};



int main() {

    worktable wt;

    hand h1(&wt, "左手");
    hand h2(&wt, "右手");

    thread t1(std::bind(&hand::moveBox, h1));       // bind 在 functional 里面
    thread t2(std::bind(&hand::moveBox, h2));

    t1.join();
    t2.join();

    return 0;
}



/*

output

左手 搬走了一个盒子 ， 还剩下：9
左手 搬走了一个盒子 ， 还剩下：8
左手 搬走了一个盒子 ， 还剩下：7
左手 搬走了一个盒子 ， 还剩下：6
左手 搬走了一个盒子 ， 还剩下：5
左手 搬走了一个盒子 ， 还剩下：4
左手 搬走了一个盒子 ， 还剩下：3
右手 搬走了一个盒子 ， 还剩下：2
右手 搬走了一个盒子 ， 还剩下：1
右手 搬走了一个盒子 ， 还剩下：0
工作台销毁了


*/