/*

����

������ϰ

*/



#include <iostream>
#include <memory>
using  namespace std;

/*
 * ö��
 *     ���޶���Χ
 */

 //�����޶���д��
 //enum class  traffic_light{ RED,GREEN,YELLOW};

 //���޶���д��
enum WEEK_DAYS { MON = 10, TUS = 20, WEN, THU, FRI, SAT, SUN };

enum class  traffic_light1 { RED1, GREEN, YELLOW }; //�޶���Χ



enum  traffic_light2 { RED, GREEN, YELLOW }; //���޶���Χ
//enum colo{RED,GREEN,BLUE}; //����ᱨ���ˡ���Ϊ��һ���Ѿ�����ͬ�����Ƶ�ö������

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
