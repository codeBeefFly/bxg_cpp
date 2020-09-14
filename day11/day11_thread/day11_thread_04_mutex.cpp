#include <iostream>
#include <thread>
#include <functional>
//#include <synchapi.h>
#include <Windows.h>

#include <mutex>  //mingw  自己安装的。

using namespace std;
/*
 *  使用mutex来解决线程并发访问的问题
 */

mutex m;


void print(string name, int time) {
    for (int i = 0; i < 10; ++i) {
        m.lock();
        cout << name << " 打印到了：" << i << endl;
        m.unlock(); //让这个线程解锁了之后，再休眠一会。 否则这个线程会立即马上持有锁。
        Sleep(time);
    }
}


void print_2(string name, int time) {
    for (int i = 0; i < 10; ++i) {
        //m.lock();
        cout << name << " 打印到了：" << i << endl;
        //m.unlock(); //让这个线程解锁了之后，再休眠一会。 否则这个线程会立即马上持有锁。
        Sleep(time);
    }
}


int main() {

    /*
    
    c++ 11推出的一套机制`bind` ，它可以预先把指定可调用实体的某些参数绑定到已有的变量，
    产生一个新的可调用实体，这种机制常常出现在回调函数中。说的简单点就是，
    有一个可以直接调用的实体，但是可以对这个实体进行一下包装，包装出来的实体，
    也可以调用，那么调用这个包装的实体，等同于调用原来的实体。
    
    */
    
    thread t1(bind(print, "线程1", 100));
    thread t2(bind(print, "线程2", 300));

    t1.join();
    t2.join();



    std::cout << "\n*******************************\n";


    thread t3(bind(print, "线程3", 100));
    thread t4(bind(print, "线程4", 300));

    t3.join();
    t4.join();


    return 0;
}