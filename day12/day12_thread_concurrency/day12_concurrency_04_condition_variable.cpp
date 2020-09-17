/*
需求：

两个线程分别答应i，只要 线程2 打印的数字能被5整除，则进入休眠状态，只有当 线程1
打印的数字能被 10 整除，才会通知 线程2 执行。

*/

#include <iostream>
//#include <synchapi.h>
#include <Windows.h>
#include <thread>
#include <mutex>
#include <condition_variable>   // 引入条件变量头文件

using namespace std;



/*
 * 条件变量
 *
 *      mutex :用来表示互斥的。多个线程抢占一个资源。
 *      在通知的线程函数里面，
 *          cv.notify_all();
 *
 *
 *      在需要等待的线程函数中，使用：
 *           unique_lock<mutex> ul(m)
 *
 *              cv.wait(ul);
 *
 */

mutex m;  //互斥元

condition_variable cv;  //条件变量

//线程1 运行的 ： 打印到了能整除10 就通知线程2起来接着打印。
void func1() {
    for (int i = 1; i < 50; ++i) {
        lock_guard<mutex>  lg(m);
        cout << "线程1:: 打印到了 " << i << endl;
        if (i % 10 == 0) {
            //在这里通知条件变量不要等了。 让出于等待的线程接着往下走。
            std::cout << "..fun1 i = " << i << "\n";
            //cv.notify_all();
            cv.notify_one();
        }
        Sleep(100);
    }
}

//线程2运行： 打印到了能整除5 就等待。
void  func2() {
    for (int i = 1; i < 50; ++i) {
        unique_lock<mutex> ul(m);
        cout << "线程2:: 打印到了-------> " << i << endl;
        if (i % 5 == 0) { //能整除5
            cv.wait(ul);
        }
        Sleep(100);
    }
}

int main() {

    thread t1(func1);
    thread t2(func2);

    t2.join();
    t1.join();

    return 0;
}
