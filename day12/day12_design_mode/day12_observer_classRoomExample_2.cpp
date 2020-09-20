#include <iostream>
//#include <synchapi.h>
#include <Windows.h>
#include <vector>
using namespace std;

/*
 * 观察者模式，
 * 自习课的时候，班里除了班长认真学习之外，有的同学玩游戏，有的同学看NBA，
 * 有的同学聊微信，此时大家想了一个法子，让班长看到班主任来的时候，通知他们，别被班主任抓到。
 *
 * 班主任来（3）， 教导主任来（5）  ， 校长也来（10）。
 *
 * 李四，不想冒险了。班长通知他一次之后，就告诉班长，以后不要通知啦。我从良~~~~我专心学习了。
 *
 */

class subject;
class obsever {
public:
    //构造函数不能是虚函数
    obsever() = default;

    //需要知道观察谁
    virtual void setSubject(subject* sj) = 0;

    //表示不想观察它绑定的那个目标对象。
    virtual void removeSubject() = 0;

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

    //有观察者不想观察目标对象了。
    virtual void removeObsever(obsever* ob) = 0;

    //要去通知观察者
    virtual void notify(string msg) = 0;

    //析构函数必须是虚函数，因为父类指针接收子类对象，最终删除的是子类对象，也要调用子类的析构
    virtual  ~subject() = default;
};


//班长类 : 被观察者。

class  Monitor : public subject {
    vector<obsever*> vo;

public:

    //添加观察者
    void addObsever(obsever* ob) override {
        vo.push_back(ob);
    }

    //移除观察者
    void removeObsever(obsever* ob) {
        for (auto i = vo.begin(); i != vo.end(); i++) {
            //*i 拿到里面的元素， 由于我们的容器的元素存的就是指针。
            if (*i == ob) {
                vo.erase(i);
            }
        }
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
    void removeSubject() {
        sj->removeObsever(this);
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

    void removeSubject() {
        sj->removeObsever(this);
    }

    //需要得到通知
    void update(string msg) {
        cout << "李四收到通知：" << msg << "  ，不要看小说了!" << endl;
    }



    //当然也不一定放在析构里面，也可以自己写一个函数。 removeSubject()
   /* ~LS(){
        //只要李四的对象销毁了，就不想受到通知了。
        sj->removeObsever(this);
    }*/
};

class WW : public obsever {

    subject* sj = nullptr;
public:
    //需要知道观察谁
    void setSubject(subject* sj) {
        this->sj = sj;
    }
    void removeSubject() {
        sj->removeObsever(this);
    }

    //需要得到通知
    void update(string msg) {
        cout << "王五收到通知：" << msg << "  ，不要聊天了!" << endl;
    }
};

//int main() {
int demo() {
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
    for (int i = 1; i < 50; ++i) {

        cout << "i ----> " << i << endl;
        if (i % 3 == 0) {
            s->notify("班主任来了！");
        }
        if (i % 7 == 0) {
            s->notify("教导主任来了！");
            ls->removeSubject();
        }
        if (i % 10 == 0) {
            s->notify("校长来了！");
        }

        Sleep(1000);
    }





    return 0;
}


class Stu {};

int main() {

    Stu* stu_0 = new Stu;
    Stu* stu_1 = new Stu;
    Stu* stu_2 = new Stu;
    Stu* stu_3 = new Stu;

    std::vector<Stu*> stu_vctor{ stu_0, stu_1, stu_2, stu_3 };

    for (Stu* stu : stu_vctor) {
        std::cout << ".. stu address:: " << stu << "\n";
    }

    int count = 0;
    for (auto i = stu_vctor.begin(); i != stu_vctor.end(); i++) {
        std::cout << "..count = " << count << "\n";
        count++;
        if (*i == stu_1) {
            i = stu_vctor.erase(i);     // erase(iter) 返回 iter
        }
    }

    std::cout << "*********************************\n";

    for (Stu* stu : stu_vctor) {
        std::cout << ".. stu address:: " << stu << "\n";
    }

    std::cout << 1 % 11 << "\n";

}