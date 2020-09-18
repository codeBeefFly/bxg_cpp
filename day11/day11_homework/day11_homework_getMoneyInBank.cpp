#include <iostream>
#include <thread>
//#include <synchapi.h>
//#include <unistd.h>
//#include <io.h>
#include <Windows.h>
#include <mutex>
#include <functional>

using namespace std;

/*
 * 银行账户有没有可能出现 -100 ???
 *  100 ：
 *      张爸 张妈都去取钱，  100.
 *
 *      张爸在柜台，取100 ， 工作人员一看，卡里有100 。给取。 看到100满足条件 --- 真正的去划走100块钱  需要5s
 *          5s过后，张爸又从柜台取走了100块。   账户就变： -100
 *
 *      张妈去ATM 取100 ，ATM程序判断，卡里有100 。 给取。 在张爸等待5秒的时候，张妈已经从ATM 取走100块钱了。
 *
 *
 */

mutex mt;


class bank {
    int money = 1000;
public:
    int getMoney(string name, int m, int sleep_time) {

        //判断余额是否充足
        mt.lock();
        if (money >= m) {

            //所谓的线程并发就是多个线程在抢占一个资源。 东西只有一份，但是来的人很多。
            //让他们排队，一个一个来，把并行变成串行。（羊肉串一样。）

            Sleep(sleep_time);
            //让账号扣钱
            money -= m; //因为money是共有的资源。
            cout << name << " 取走了 " << m << " ，账户还剩 ： " << money << endl;
            mt.unlock();
            return 1;
        }
        else {
            cout << name << " 想取钱，但是余额不足！" << endl;
            mt.unlock();
            return 0;
        }


    }
};

class human {

    //持有银行的对象
    bank* b;
    string name;
public:
    human(bank* b, string name) : b(b), name(name) {

    }

    void getMoney(int money, int sleep_time) {
        while (true) {
            //调用银行的取钱函数
            int result = b->getMoney(name, money, sleep_time);
            if (result == 0) {
                break;
            }

        }
    }

};

int main() {

    //1 创建银行对象
    bank b;

    //2. 两个客户
    human h1(&b, "张爸");
    human h2(&b, "张妈");

    //3. 使用线程模拟两个人取钱。
    thread t1(std::bind(&human::getMoney, h1, 100, 300));
    thread t2(std::bind(&human::getMoney, h2, 100, 200));


    t1.join();
    t2.join();

    return 0;
}


/*
output:


张爸 取走了 100 ，账户还剩 ： 900
张妈 取走了 100 ，账户还剩 ： 800
张妈 取走了 100 ，账户还剩 ： 700
张妈 取走了 100 ，账户还剩 ： 600
张爸 取走了 100 ，账户还剩 ： 500
张妈 取走了 100 ，账户还剩 ： 400
张妈 取走了 100 ，账户还剩 ： 300
张爸 取走了 100 ，账户还剩 ： 200
张爸 取走了 100 ，账户还剩 ： 100
张爸 取走了 100 ，账户还剩 ： 0
张妈 想取钱，但是余额不足！
张爸 想取钱，但是余额不足！

D:\W_workPlace\bxg_cpp\day11\build\Debug\day11_homework_getMoneyInBank.exe (process 28412) exited with code 0.
Press any key to close this window . . .


*/