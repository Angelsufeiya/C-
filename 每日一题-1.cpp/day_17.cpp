//����:iNOC��Ʒ�� - ������ǵı���
//	1
//	1 1 1
//	1 2 3 2 1
//	1 3 6 7 6 3 1
//	1 4 10 16 19 16 10 4 1
//	���������ε����󣬵�һ��ֻ��һ����1������ÿ�е�ÿ��������ǡ������������������Ͻ��������Ͻǵ� ����3����֮��(���������ĳ��������Ϊ��������0)��
//	���n�е�һ��ż�����ֵ�λ�á����û��ż��������� - 1����������3, �����2������4�����3��
//	����n(n <= 1000000000)
//��������: ����һ��int����
//  ������� : ������ص�intֵ
//	 ʾ��1 :
//   ���� 4
//	   ��� 3
//
//


#if 0
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;

void (*PF)();
int main()
{
	auto f1 = [] {cout << "hello world" << endl; };
	auto f2 = [] {cout << "hello world" << endl; };
	// �˴��Ȳ�����ԭ�򣬵�lambda���ʽ�ײ�ʵ��ԭ����󣬴�Ҿ������ 
	//f1 = f2; // ����ʧ��--->��ʾ�Ҳ���operator=()
	// ����ʹ��һ��lambda���ʽ��������һ���µĸ���
	auto f3(f2);
	f3();
	// ���Խ�lambda���ʽ��ֵ����ͬ���͵ĺ���ָ�� 
	PF = f2;
	PF();

	cout << typeid(f1).name() << endl;	// class <lambda_1ec5592de10118e452907b5329e9d8fb>
	cout << typeid(f2).name() << endl;	// class <lambda_6c39677baa7253626f0848c76a9ffef5>
	cout << typeid(f3).name() << endl;	// class <lambda_6c39677baa7253626f0848c76a9ffef5>
	cout << typeid(PF).name() << endl;	// void(__cdecl*)(void)

	return 0;
}

#endif

#include <iostream>
#include <thread>
using namespace std;

void func(int i, int j)
{
	cout << "I am thread." << i << ' ' << j << endl;
}

int main()
{
	thread t1(func, 2, 5);
	thread t2(func, 3, 8);

	t1.join();
	t2.join();

	cout << "I am main thread." << endl;
	return 0;
}


//
//
//
//   ����:�������������
//	 �����һ���㷨������������������ļӷ���
//	  �ӿ�˵��
//	  /*
//	  �����һ���㷨������������������ļӷ��� �������:
//	  String addend:����
//	  String augend:������
//	  ����ֵ:�ӷ����
//	  */
//	  public String AddLongInteger(String addend, String augend) {
//		  /*������ʵ�ֹ���*/
//		  return null;
//	  }
//��������:
//   ���������ַ�������
//   ������� : �����Ӻ�Ľ����string��
//	  ʾ��1 :
//   ���� 99999999999999999999999999999999999999999999999999 1
//	   ���
//	   100000000000000000000000000000000000000000000000000