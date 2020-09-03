/*

����


 * һ�Һ���ݿ�ҵ�ˣ��ſڹ�������˵����ӭ���������Ӿ��
 * ���˼��죬��������ʾ����ӭ����Ҳ������Ӿ��
 * �ֹ��˼��죬˵��ӭ�޷���Ҳ������Ӿ�����ɴ�ֱ��˵�ˣ�
 * ֻҪ������Ķ����Խ�����Ӿ����ʹ����������˼�룬
 
 * ��ƺ���ݹݽ�������Ĺ��̡� ��̬��
 


    shark s;            //����
    crocodile c;        //����
    Tilapia t;          //����

    Aquarium

*/


/******************* test code *******************/
//#include <iostream>
//
//class Father {
//public:
//	Father() {
//		std::cout << "..�����޲�...\n";
//	}
//	~Father() {
//		std::cout << "..�����в�...\n";
//	}
//
//	void smoke() {
//		std::cout << "..�����ڳ���...\n";
//	}
//};
//
//class Son : public Father {
//public:
//	Son() {
//		std::cout << "..�����޲�...\n";
//	}
//	~Son() {
//		std::cout << "..�����в�...\n";
//	}
//
//	void smoke() {		// ����� virtual void smoke() ���ߺ��ӵ� smoke()
//		std::cout << "..�����ڳ���...\n";
//	}
//};
//
//
//int main() {
//
//	std::cout << "..in practice_test...\n";
//
//	Father* f = new Son;
//	f->smoke();		//..�����ڳ���... ��Ϊ ����� smoke û�� virtul
//
//
//	return 0;
//}

/*

output

..in practice_test...
..�����޲�...
..�����޲�...
..�����ڳ���...

*/

/******************* test code *******************/


/*

����


 * һ�Һ���ݿ�ҵ�ˣ��ſڹ�������˵����ӭ���������Ӿ��
 * ���˼��죬��������ʾ����ӭ����Ҳ������Ӿ��
 * �ֹ��˼��죬˵��ӭ�޷���Ҳ������Ӿ�����ɴ�ֱ��˵�ˣ�
 * ֻҪ������Ķ����Խ�����Ӿ����ʹ����������˼�룬

 * ��ƺ���ݹݽ�������Ĺ��̡� ��̬��



    shark s;            //����
    crocodile c;        //����
    Tilapia t;          //����

    Aquarium


1. ʹ�ö�̬��̬
2. Fish Ϊ���࣬swim Ϊ�麯��
3. ���� Shark��Crocodile��Tilapia �̳� Fish ��
4. Aquarium ��������࣬����ͨ����̬��̬���ֲ�ͬ��������
  

*/


#include <iostream>


class Fish {
public:

    virtual void swim() {
        std::cout << "..������Ӿ...\n";
    }

};


class Shark : public Fish {     // û�з������Σ�convert to inaccessible base is not allowed
public:
    void swim() {
        std::cout << "..shark ����Ӿ...\n";
    }
};


class Crocodile : public Fish {
public:
    void swim() {
        std::cout << "..Crocodile ����Ӿ...\n";
    }
};


class Tilapia : public Fish {
public:
    void swim() {
        std::cout << "..Tilapia ����Ӿ...\n";
    }
};


class Aquarim {
public:
    void welcome_to_swim(Fish* f){  // ��̬��̬
        f->swim();
    }

};

int main() {

    std::cout << "..practice_fish...\n";

    Aquarim aq;

    aq.welcome_to_swim(new Shark);
    aq.welcome_to_swim(new Crocodile);
    aq.welcome_to_swim(new Tilapia);


    return 0;
}


/*

..practice_fish...
..shark ����Ӿ...
..Crocodile ����Ӿ...
..Tilapia ����Ӿ...


*/

