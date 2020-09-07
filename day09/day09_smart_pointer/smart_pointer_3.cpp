/*

需求：

shared_ptr


`shared_ptr` : 允许多个智能指针指向同一个位置 ， 针对的是 `shared_ptr`。
所以为了保证最后的释放回收，采用了计数处理，每一次的指向计数 + 1 ， 
每一次的reset会导致计数 -1 ，直到最终为0 ，内存才会最终被释放掉。 
可以使用`use_cout` 来查看目前的指针个数  count

*/


#include <iostream>
#include <memory>

using  namespace std;

/*
 *  共享指针
 *      用法基本和唯一指针一样，声明、初始化，取值，都是一样。
 *      不同点：
 *          a. 可以拷贝。
 *         b. 可以允许多个shared_ptr 管理一个指针，指向同一个地方。
 *              没增加一个shared_ptr 那么计数 + 1
 *              只有最后的计数为0 ，才会回收内存
 *                  可以手动reset  让这个计数 -1 。
 */

class stu {
public:
    string name;
    stu() = default;
    stu(string name) : name(name) {
        cout << "构造学生 :" << name << endl;
    }

    ~stu() {
        cout << "析构 :" << name << endl;
    }

};

int main() {

    //1. 创建共享指针。
    stu* s = new stu("李四");

    shared_ptr<stu> sp(s);
    //sp.reset(s); 表示赋值，管理指针 s
    cout << "智能指针的计数1 sp：" << sp.use_count() << endl;

    //2. 可以拷贝吗？  可以拷贝，可以移动。
    shared_ptr<stu> sp1 = sp;
    cout << "智能指针的计数2 sp：" << sp.use_count() << endl;

    shared_ptr<stu> sp2 = move(sp);
    cout << "智能指针的计数3 sp：" << sp.use_count() << endl; //这句话返回的计数是0，因为sp已经移动给了sp2
    cout << "智能指针的计数3 sp2：" << sp2.use_count() << endl;

    //3. 取值
    cout << "取值1：" << sp2.get()->name << endl;
    cout << "取值2：" << (*sp2).name << endl;
    cout << "取值3：" << sp2->name << endl;

    //4. 什么时候释放指针。
    sp1.reset();
    cout << "智能指针的计数4 sp2：" << sp2.use_count() << endl;

    sp2.reset();  // 计数已经变成0  触发析构函数  打印析构语句。
    cout << "智能指针的计数5 sp2：" << sp2.use_count() << endl;

    cout << "这是最后打印的语句！！！" << endl;

    return 0;
}


/*

output


构造学生 :李四
智能指针的计数1：1
智能指针的计数2：2
智能指针的计数3：0
智能指针的计数3：2
取值1：李四
取值2：李四
取值3：李四
智能指针的计数4：1
析构 :李四
智能指针的计数5：0
这是最后打印的语句！！！

*/
