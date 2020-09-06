#include <iostream>
#include <string>

using namespace std;

/*
 * 现在要比较两个学生的大小，可以按照名字多少排序比较、也可以按照年龄比较、也可以按照身高比较。
定义一个全局函数compare , 接收三个参数，参数一和参数二 为要比较的学生对象，参数三为lambda表达式
如果姓名一样，则比较年龄，如果年龄一样，则表示两者相等，否则打印两人的大小。
 */

class stu {
public:
    string name;
    int age;

    stu() : stu("unknown", 0) {}
    stu(string name, int age) :name(name), age(age) {

    }
    //这个函数是我们类的一个好基友。
    //实际上这个函数属不属于我们类的一份子呢？ 还是这个函数应该属于ostream类型。
    //这个友元函数是全局函数。
    //friend void operator<<( ostream& os , stu &s);
};

int compare(stu s1, stu s2, int(*cp)(stu, stu)) {
    return cp(s1, s2);
}

int main() {
    stu s1("zhangsan", 28);
    stu s2("zhangsan", 28);

    //对于做SDK （开发API给别人用。）不要再里面返回字符串。 1  0  -1
    /*int(*cp)(stu , stu)  =  [](stu s1 , stu s2){
        //在这里比较了。
        if(s1.name == s2.name){
            //相等，还要比较年龄。
            if(s1.age == s2.age){
                return 0 ;
            }else if(s1.age > s2.age){
                return 1;
            }else if(s1. age < s2.age){
                return -1;
            }
        }else if(s1.name > s2. name){
            return 1;
        }else if(s1 .name < s2.name){
            return -1;
        }
        return 1;
    };
    int result = compare(s1, s2 , cp);*/


    //更希望大家写这样的代码。
    //1. 开发效率更高。。但是上面的写法更好理解
    //2. 这种代码写多了，那么编程思想也就上来了。
    //    以后如果看见某一个函数的其中一个参数用的是函数指针。
    //       那么可以大胆猜测， 实际上这个函数的背后就是会调用我们传递进去的这个函数指针。
    int result = compare(s1, s2, [](stu s1, stu s2) {
        //在这里比较了。
        if (s1.name == s2.name) {
            //相等，还要比较年龄。
            if (s1.age == s2.age) {
                return 0;
            }
            else if (s1.age > s2.age) {
                return 1;
            }
            else if (s1.age < s2.age) {
                return -1;
            }
        }
        else if (s1.name > s2.name) {
            return 1;
        }
        else if (s1.name < s2.name) {
            return -1;
        }
        return 1;
        });
    cout << "result = " << result << endl;

    return 0;
}
