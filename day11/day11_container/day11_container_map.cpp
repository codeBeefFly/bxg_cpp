
#include <iostream>
#include <string>
#include <map>

using namespace std;
/*
 * 关联容器 - map
 *
 */

int main() {

    // pair<string , int> p1("张三",100) ;

    //创建了一个map
    map<string, int> m;

    //存东西
    pair<string, int > p("张三", 100);        // 创建一个键值

    m.insert(p);


    m.insert({ "李四",95 });

    //取值 如果有这个key存在，就返回，如果没有就直接报错。
    int result = m.at("张三");
    cout << "result = " << result << endl;



    return 0;
}

/*

output

result = 100
 
*/
