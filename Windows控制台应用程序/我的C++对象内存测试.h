#pragma once

#include"stdafx.h"
class SomeBasicClass {
public:
	int firstMemberField;
	int secondMemberField;
	//static int firstStaticField;
	//static int secondStaticField;
	SomeBasicClass(){
		cout << "SomeBasicClass()\n";
		firstMemberField = -1;
		secondMemberField = 0;
	}
	SomeBasicClass(int i) {
		firstMemberField = i;
		secondMemberField = i + 1;
		cout << "SomeBasicClass(int)\n";
	}
	void firstMemberFunction() {
		cout << "SomeBasicClass::firstMemberFunction()\n";
	}
	void secondMemberFunction() {
		cout << "SomeBasicClass::secondMemberFunction()\n";
	}
	void constMemberFunction() const {
		cout << "SomeBasicClass::constMemberFunction()\n";
	}
	virtual void firstVirtualFunction() {
		cout << "SomeBasicClass::firstVirtualFunction()\n";
	}
	virtual void secondVirtualFunction() {
		cout << "SomeBasicClass::secondVirtualFunction()\n";
	}
	~SomeBasicClass() {
		cout << "~SomeBasicClass()\n";
	}
	static void firstStaticFunction() {
		//firstStaticField = 120;
		cout << "SomeBasicClass.firstStaticFunction()\n";
	}
	static void secondStaticFunction() {
		//secondStaticField = 150;
		cout << "SomeBasicClass.secondStaticFunction()\n";
	}
};
class Test {
private:
	void test() {
		SomeBasicClass b;
		cout << "对象地址：" << &b << endl;
		cout << "对象大小：" << sizeof(b) << endl;
		cout << "虚函数表地址：" << (int*)&b << endl;
		cout << "虚函数表的第一个虚函数地址：" << (int*)*((int*)&b) << endl;
		Fun firstVirtualFunction = (Fun)* ((int*)*(int*)(&b));
		cout << "调用第一个虚函数：" << ((int*)*(int*)(&b)) << endl;
		firstVirtualFunction();
		cout << "调用第二个虚函数：" << ((int*)*(int*)(&b) + 1) << endl;
		Fun secondVirtualFunction = (Fun)* ((int*)*(int*)(&b) + 1);
		secondVirtualFunction();
		cout << "析构函数的地址:" << (int*)*(int *)*((int*)(&b)) << endl;
		Fun destructFunction = (Fun)* (int*)*(int *)*((int*)(&b));
		//destructFunction();
		b.firstStaticFunction();
		b.secondStaticFunction();
		cout << "第一个静态函数地址：" << b.firstStaticFunction << endl;
		cout << "第二个静态函数地址：" << b.secondStaticFunction << endl;
		cout << "第一个成员变量地址：" << (int*)(&b) + 1 << endl;
		cout << "第一个成员变量：" << *((int*)(&b) + 1) << endl;
		cout << "第二个成员变量地址：" << (int*)(&b) + 2 << endl;
		cout << "第二个成员变量：" << *((int*)(&b) + 2) << endl;
	}
public:
	Test() {
		test();
	}
};

