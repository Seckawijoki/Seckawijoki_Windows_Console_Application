#include"stdafx.h"
class Base {
public:
	Base(int i) :baseI(i) { cout << "Base(int)\n"; };
	int getI() { cout << "getI()\n";return baseI; }
	static void countI() { cout << "static void countI();\n"; };
	virtual ~Base() { cout << "virtual ~Base()"; }
	virtual void print(void) { cout << "Base::print()"; }
private:
	int baseI;
	static int baseS;
};
class Derive : public Base {
public:
	Derive(int d) :Base(1000), DeriveI(d) {};
	//overwrite�����麯��
	virtual void print(void) { cout << "Drive::print()"; }
	// Derive�������µ��麯��
	virtual void Drive_print() { cout << "Drive::Drive_print()"; }
	virtual ~Derive() {}
private:
	int DeriveI;
};
class Test {
private:
	void main() {
		typedef void(*Fun)(void);
		Derive d(2000);
		//[0]
		cout << "[0]Base::vptr";
		cout << "\t��ַ��" << (int *)(&d) << endl;
		//vprt[0]
		cout << "  [0]";
		Fun fun1 = (Fun)*((int *)*((int *)(&d)));
		//        fun1();
		cout << "\t��ַ:\t" << *((int *)*((int *)(&d))) << endl;

		//vprt[1]���������޷�ͨ����ַ���ã����ֶ����
		cout << "  [1]" << "Derive::~Derive" << endl;

		//vprt[2]
		cout << "  [2]";
		Fun fun2 = (Fun)*((int *)*((int *)(&d)) + 2);
		fun2();
		cout << "\t��ַ:\t" << *((int *)*((int *)(&d)) + 2) << endl;
		//[1]
		cout << "[1]Base::baseI=" << *(int*)((int *)(&d) + 1);
		cout << "\t��ַ��" << (int *)(&d) + 1;
		cout << endl;
		//[2]
		cout << "[2]Derive::DeriveI=" << *(int*)((int *)(&d) + 2);
		cout << "\t��ַ��" << (int *)(&d) + 2;
		cout << endl;
		getchar();
	}
public:
	Test() {
		main();
	}
};
