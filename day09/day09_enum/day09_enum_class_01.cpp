/*

需求：

继续练习

*/



#include <iostream>
#include <memory>
using  namespace std;

/*
 * 枚举
 *     不限定范围
 */

 //这是限定的写法
 //enum class  traffic_light{ RED,GREEN,YELLOW};

 //不限定的写法
enum WEEK_DAYS { MON = 10, TUS = 20, WEN, THU, FRI, SAT, SUN };

enum class  traffic_light1 { RED1, GREEN, YELLOW }; //限定范围



enum  traffic_light2 { RED, GREEN, YELLOW }; //不限定范围
//enum colo{RED,GREEN,BLUE}; //这里会报错了。因为上一句已经有了同样名称的枚举量。

int main() {

    cout << "mon :" << MON << endl;
    cout << "tus :" << WEEK_DAYS::TUS << endl;
    cout << "wen :" << WEN << endl;


    return 0;
}


/*

output:


mon :10
tus :20
wen :21

*/
