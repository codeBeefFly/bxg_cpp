/*

����
��������

1. ����ָ��
int add(int, int)

int (*p_add)(int, int) = add;
p_add(3, 4);


2. function ����ȫ�ֺ��� ͷ <functional>

void print(int a, string b);

function<�������� (��������, ...)> function���� = ������;


3, function ���� lambda 

function<�������� (��������, ...)> function���� = [](�������� ����, ...){ return ...; };


4. ���վ�̬��Ա����

class Stu{
public:
	static int run(string name, int age);
}

function<int (string, int)> f = stu::run;


5. ���ճ�Ա����

class Stu{
public:
	int run(string name, int age);

}


function<int (Stu, string, age)> f1 = &Stu::run;	// &-ȡ��ַ	// ��һ�������������
function<int (Stu&, string, age)> f1 = &Stu::run;	// ��һ�����������������
function<int (Stu*, string, age)> f1 = &Stu::run;	// ��һ�������������ָ��

*/



/*

���ֺ����ĵ���


������ʹ�ú���ָ�������ú���֮�⣬��ʵҲ��������һ��`function`�Ķ���
����ĳһ��������ֱ�ӵ���function�Ķ���Ҳ��ͬ�ڵ��ú�����

*/

#include <iostream>
#include <functional>

using namespace std;

/*
 * function
 */

int add(int a, int b) {
    return a + b;
}

void sayHi() {
    cout << "�������" << endl;
}

int main() {

    //ֱ�ӵ���
    cout << add(3, 4) << endl;

    //����ָ�뷽ʽ����
    int(*padd)(int, int) = add;
    cout << padd(3, 4) << endl;


    //<> �������κ����ķ���ֵ�ͺ����Ĳ���
    // ��һ��int�Ǻ����ķ���ֵ
    //() ���ڱ�ʾ�����Ĳ����� ����������������int���͡�
    function <int(int, int)>f2 = add;


    function<int(int, int)> f = add;
    cout << f(3, 4) << endl;

    //�޲Σ��޷���ֵ��ҲҪ����() �� void
    void (*psayHi)() = sayHi;
    function<void()> f3 = sayHi;



    return 0;
}

/*

output


7
7
7

*/