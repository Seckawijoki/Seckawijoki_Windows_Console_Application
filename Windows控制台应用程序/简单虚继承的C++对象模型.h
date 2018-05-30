#include"stdafx.h"
class B{
public:
    int ib;
public:
    B(int i=1) :ib(i){}
    virtual void f() { cout << "B::f()" << endl; }
    virtual void Bf() { cout << "B::Bf()" << endl; }
};
class B1 : virtual public B{
public:
    int ib1;
public:
    B1(int i = 100 ) :ib1(i) {}
    virtual void f() { cout << "B1::f()" << endl; }
    virtual void f1() { cout << "B1::f1()" << endl; }
    virtual void Bf1() { cout << "B1::Bf1()" << endl; }
};
class Test {
private:
	void main() {
			typedef void(*Fun)(void);
			B1 a;
			cout << "B1�����ڴ��СΪ��" << sizeof(a) << endl;

			//ȡ��B1���麯����
			cout << "[0]B1::vptr";
			cout << "\t��ַ��" << (int *)(&a) << endl;

			//������B1::vptr�еĺ���
			for (int i = 0; i<2;++i) {
				cout << "  [" << i << "]";
				Fun fun1 = (Fun)*((int *)*(int *)(&a) + i);
				fun1();
				cout << "\t��ַ��\t" << *((int *)*(int *)(&a) + i) << endl;
			}

			//[1]
			cout << "[1]vbptr ";
			cout << "\t��ַ��" << (int *)(&a) + 1 << endl;  //���ָ��ĵ�ַ
														 //��������ָ����Ŀ��ָ������
			for (int i = 0; i < 2; i++) {
				cout << "  [" << i << "]";
				cout << *(int *)((int *)*((int *)(&a) + 1) + i);
				cout << endl;
			}




			//[2]
			cout << "[2]B1::ib1=" << *(int*)((int *)(&a) + 2);
			cout << "\t��ַ��" << (int *)(&a) + 2;
			cout << endl;

			//[3]
			cout << "[3]ֵ=" << *(int*)((int *)(&a) + 3);
			cout << "\t\t��ַ��" << (int *)(&a) + 3;
			cout << endl;

			//[4]
			cout << "[4]B::vptr";
			cout << "\t��ַ��" << (int *)(&a) + 3 << endl;

			//���B::vptr�е��麯��
			for (int i = 0; i<2; ++i) {
				cout << "  [" << i << "]";
				Fun fun1 = (Fun)*((int *)*((int *)(&a) + 4) + i);
				fun1();
				cout << "\t��ַ:\t" << *((int *)*((int *)(&a) + 4) + i) << endl;
			}

			//[5]
			cout << "[5]B::ib=" << *(int*)((int *)(&a) + 5);
			cout << "\t��ַ: " << (int *)(&a) + 5;
			cout << endl;          //��ȷ
			getchar();
	}
public:
	Test() {
		main();
	}
};
