#include <iostream>
//#include <synchapi.h>
#include <Windows.h>
#include <vector>
using namespace std;

/*
 * 观察者模式，
 * 自习课的时候，班里除了班长认真学习之外，有的同学玩游戏，有的同学看NBA，
 * 有的同学聊微信，此时大家想了一个法子，让班长看到班主任来的时候，通知他们，别被班主任抓到。
 */

class subject;
class obsever {
public:
    //构造函数不能是虚函数
    obsever() = default;

    //需要知道观察谁
    virtual void setSubject(subject* sj) = 0;

    //需要得到通知
    virtual void update(string msg) = 0;

    //析构函数必须是虚函数，因为父类指针接收子类对象，最终删除的是子类对象，也要调用子类的析构
    virtual  ~obsever() = default;
};

class subject {

public:
    //不能在父类写这行代码，因为不是所有的目标对象都有一群人观察者。
    //vector <obsever*> vo;
    //构造函数不能是虚函数
    subject() = default;

    //需要知道被谁观察。
    virtual void addObsever(obsever* ob) = 0;

    //要去通知观察者
    virtual void notify(string msg) = 0;

    //析构函数必须是虚函数，因为父类指针接收子类对象，最终删除的是子类对象，也要调用子类的析构
    virtual  ~subject() = default;
};


//班长类 : 被观察者。

class  Monitor : public subject {
    vector<obsever*> vo;

public:
    void addObsever(obsever* ob) override {
        vo.push_back(ob);
    }

    void notify(string msg) override {
        cout << "班长已经到达了某种状态，要去通知观察者了" << endl;
        for (obsever* ob : vo) {
            ob->update(msg);
        }
    }
};

//
class ZS : public obsever {

    subject* sj = nullptr;
public:
    //需要知道观察谁
    void setSubject(subject* sj) {
        this->sj = sj;
    }

    //需要得到通知
    void update(string msg) {
        cout << "张三收到通知：" << msg << "  ，不要玩游戏了!" << endl;
    }
};


class LS : public obsever {

    subject* sj = nullptr;
public:
    //需要知道观察谁
    void setSubject(subject* sj) {
        this->sj = sj;
    }

    //需要得到通知
    void update(string msg) {
        cout << "李四收到通知：" << msg << "  ，不要看小说了!" << endl;
    }
};

class WW : public obsever {
    subject* sj = nullptr;
public:
    //需要知道观察谁
    void setSubject(subject* sj) {
        this->sj = sj;
    }

    //需要得到通知
    void update(string msg) {
        cout << "王五收到通知：" << msg << "  ，不要聊天了!" << endl;
    }
};

int main() {


    //1. 创建目标对象
    subject* s = new Monitor();

    //2. 创建观察者
    obsever* zs = new ZS();
    obsever* ls = new LS();
    obsever* ww = new WW();

    //3. 设置目标对象被谁观察
    s->addObsever(zs);
    s->addObsever(ls);
    s->addObsever(ww);

    //4. 设置观察者观察哪个目标对象
    zs->setSubject(s);
    ls->setSubject(s);
    ww->setSubject(s);

    //5. 模拟班主任来了。
    for (int i = 1; i < 20; ++i) {

        cout << "i ----> " << i << endl;
        if (i % 5 == 0) {
            s->notify("班主任来了！");
        }

        Sleep(1000);
    }

    return 0;
}

/*

output:


i ----> 1
i ----> 2
i ----> 3
i ----> 4
i ----> 5
班长已经到达了某种状态，要去通知观察者了
张三收到通知：班主任来了！  ，不要玩游戏了!
李四收到通知：班主任来了！  ，不要看小说了!
王五收到通知：班主任来了！  ，不要聊天了!
i ----> 6
i ----> 7
i ----> 8
i ----> 9
i ----> 10
班长已经到达了某种状态，要去通知观察者了
张三收到通知：班主任来了！  ，不要玩游戏了!
李四收到通知：班主任来了！  ，不要看小说了!
王五收到通知：班主任来了！  ，不要聊天了!
i ----> 11
i ----> 12
i ----> 13
i ----> 14
i ----> 15
班长已经到达了某种状态，要去通知观察者了
张三收到通知：班主任来了！  ，不要玩游戏了!
李四收到通知：班主任来了！  ，不要看小说了!
王五收到通知：班主任来了！  ，不要聊天了!
i ----> 16
i ----> 17
i ----> 18
i ----> 19


*/
