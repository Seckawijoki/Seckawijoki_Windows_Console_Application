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
		cout << "�����ַ��" << &b << endl;
		cout << "�����С��" << sizeof(b) << endl;
		cout << "�麯�����ַ��" << (int*)&b << endl;
		cout << "�麯����ĵ�һ���麯����ַ��" << (int*)*((int*)&b) << endl;
		Fun firstVirtualFunction = (Fun)* ((int*)*(int*)(&b));
		cout << "���õ�һ���麯����" << ((int*)*(int*)(&b)) << endl;
		firstVirtualFunction();
		cout << "���õڶ����麯����" << ((int*)*(int*)(&b) + 1) << endl;
		Fun secondVirtualFunction = (Fun)* ((int*)*(int*)(&b) + 1);
		secondVirtualFunction();
		cout << "���������ĵ�ַ:" << (int*)*(int *)*((int*)(&b)) << endl;
		Fun destructFunction = (Fun)* (int*)*(int *)*((int*)(&b));
		//destructFunction();
		b.firstStaticFunction();
		b.secondStaticFunction();
		cout << "��һ����̬������ַ��" << b.firstStaticFunction << endl;
		cout << "�ڶ�����̬������ַ��" << b.secondStaticFunction << endl;
		cout << "��һ����Ա������ַ��" << (int*)(&b) + 1 << endl;
		cout << "��һ����Ա������" << *((int*)(&b) + 1) << endl;
		cout << "�ڶ�����Ա������ַ��" << (int*)(&b) + 2 << endl;
		cout << "�ڶ�����Ա������" << *((int*)(&b) + 2) << endl;
	}
public:
	Test() {
		test();
	}
};

