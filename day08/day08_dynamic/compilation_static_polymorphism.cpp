/*

����

��̬����

ѧϰģʽ�������γ̴��룬���ԣ����У��ܽ�

*/


#include <iostream>
#include <string>

using namespace std;

/*
 * ��̬
 *      ��̬��̬ ���ڱ����ڼ���Ѿ���ȷ��Ҫִ��ʲô������ �������ء�
 */

int add(int a, int b) {
    return a + b;
}

int add(double a, int b) {
    return a + b;
}

int main() {

    std::cout << "..in compilation_static...\n";

    std::cout << add(3.3, 4) << "\n";
    std::cout << add(3, 4) << "\n";

    return 0;
}
