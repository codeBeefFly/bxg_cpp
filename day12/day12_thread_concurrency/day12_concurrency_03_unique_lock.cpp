/*

需求：  

 `unique_guard` 拥有 `lock_guard`的所有功能，并且内部还提供了加锁和解锁的操作，
 以便对加锁的粒度进行细化，而 `lock_guard` 的加锁范围通常是一个范围区域（比如函数） 。
 `unique_lock` 对于锁的管理比较灵活.它不像`lock_guard` 一样.
 必须要求他管理的锁在他初始化的时候必须加锁.而是可以自己灵活的.想加锁.就加锁.


练习 unique_lock  唯一锁


*/



#include <iostream>
#include <queue>
//#include <synchapi.h>
#include <Windows.h>
#include <thread>
#include <mutex>

using namespace std;



/*
 * unique_lock
 */

mutex m;

void print() {
    for (int i = 0; i < 10; ++i) {

        //让加锁的范围更加细化
        unique_lock<mutex> ul(m);
        cout << this_thread::get_id() << " 号线程打印到了：" << i << endl;
        ul.unlock();

        Sleep(300);
    }
}

int main() {

    thread t1(print);
    thread t2(print);

    t1.join();
    t2.join();

    return 0;
}


/*

output:


5896 号线程打印到了：0
23132 号线程打印到了：0
5896 号线程打印到了：1
23132 号线程打印到了：1
5896 号线程打印到了：2
23132 号线程打印到了：2
5896 号线程打印到了：3
23132 号线程打印到了：3
5896 号线程打印到了：4
23132 号线程打印到了：4
5896 号线程打印到了：5
23132 号线程打印到了：5
5896 号线程打印到了：6
23132 号线程打印到了：6
5896 号线程打印到了：7
23132 号线程打印到了：7
5896 号线程打印到了：8
23132 号线程打印到了：8
5896 号线程打印到了：9
23132 号线程打印到了：9



*/
