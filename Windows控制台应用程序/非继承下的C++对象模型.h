#include"stdafx.h"
#include<sys/types.h>
class Base
{
public:
    Base(int i) :baseI(i){};
    int getI(){ return baseI; }
    static void countI(){cout<<"static void countI();\n";};
    virtual ~Base(){cout<<"virtual ~Base()";}
    virtual void print(void){ cout << "Base::print()"; }
private:
    int baseI;
    static int baseS;
};
class Test{
private:
	void testBase(Base&p) {
		typedef void(*Fun)(void);
		cout << "������ڴ���ʼ��ַ��" << &p << endl;
		    cout << "type_info��Ϣ:" << endl;
		    //RTTICompleteObjectLocator str = *((RTTICompleteObjectLocator*)*((int*)*(int*)(&p) - 1));

		    //string classname(str.pTypeDescriptor->name);
		    //classname = classname.substr(4, classname.find("@@") - 4);
		    //cout <<  "����type_info��Ϣ�������:"<< classname << endl;

		cout << "�麯�����ַ:" << (int *)(&p) << endl;

		//��֤���
		cout << "�麯�����һ�������ĵ�ַ��" 
			<<          (int *)*((int*)(&p)) << endl;
		cout << "���������ĵ�ַ:" 
			<< (int*)*(int *)*((int*)(&p)) << endl;
		cout << "�麯�����У��ڶ����麯����print()�ĵ�ַ��" << ((int*)*(int*)(&p) + 1) << endl;

		//ͨ����ַ�����麯��print()
		Fun IsPrint = (Fun)* ((int*)*(int*)(&p) + 1);
		cout << endl;
		cout<<"�������麯��";
		IsPrint(); //����ַ��ȷ���������Base����麯��print()
		cout << endl;

		//����static�����ĵ�ַ
		p.countI();//�ȵ��ú����Բ���һ��ʵ��
		cout << "static����countI()�ĵ�ַ��" << p.countI << endl;

		//��֤nonstatic���ݳ�Ա
		cout << "�Ʋ�nonstatic���ݳ�ԱbaseI�ĵ�ַ��" << (int *)(&p) + 1 << endl;
		cout << "�����Ʋ���ĵ�ַ������õ�ַ��ֵ��" << *((int *)(&p) + 1) << endl;
		cout << "Base::getI():" << p.getI() << endl;
	}
void main(){
	Base b(1000);
	testBase(b);
}
public:
	Test() {
		main();
	}
};
