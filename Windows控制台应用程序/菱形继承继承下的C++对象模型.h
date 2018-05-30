#include"stdafx.h"
class B{
public:
    int ib;
public:
    B(int i=1) :ib(i){}
    virtual void f() { cout << "B::f()" << endl; }
    virtual void Bf() { cout << "B::Bf()" << endl; }
};
class B1 : public B{
public:
    int ib1;
public:
    B1(int i = 100 ) :ib1(i) {}
    virtual void f() { cout << "B1::f()" << endl; }
    virtual void f1() { cout << "B1::f1()" << endl; }
    virtual void Bf1() { cout << "B1::Bf1()" << endl; }
};
class B2 : public B{
public:
    int ib2;
public:
    B2(int i = 1000) :ib2(i) {}
    virtual void f() { cout << "B2::f()" << endl; }
    virtual void f2() { cout << "B2::f2()" << endl; }
    virtual void Bf2() { cout << "B2::Bf2()" << endl; }
};
class D : public B1, public B2{
public:
    int id;
public:
    D(int i= 10000) :id(i){}
    virtual void f() { cout << "D::f()" << endl; }
    virtual void f1() { cout << "D::f1()" << endl; }
    virtual void f2() { cout << "D::f2()" << endl; }
    virtual void Df() { cout << "D::Df()" << endl; }
};
class Test {
private:

	int main() {
		D d;
		//	d.ib =1 ;               //�����Դ���,���õ���B1��ib����B2��ib��
		d.B1::ib = 1;           //��ȷ
		d.B2::ib = 1;           //��ȷ
		return 0;
	}
public:
	Test() {
		main();
	}
};
