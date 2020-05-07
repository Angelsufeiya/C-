//
//������n���ַ����ַ��������������ַ������ȶ��ǲ�ͬ�ġ��������ѧϰ���������ַ��������򷽷� :
//1.�� ���ַ������ֵ����������� :
//"car" < "carriage" < "cats" < "doggies < "koala"
//2.�����ַ����ĳ����������� : "car" < "cats" < "koala" <
//"doggies" < "carriage"
//������֪���Լ�����Щ�ַ�������˳���Ƿ��������������򷽷�������Ҫæ�ų���Ҷ��������Ҫ������æ�� ֤��
//�������� :
//�����һ��Ϊ�ַ�������n(n �� 100) ��������n��, ÿ��һ���ַ���, �ַ������Ⱦ�С��100������Сд��ĸ���
//������� : �����Щ�ַ����Ǹ����ֵ������ж����Ǹ��ݳ����������"lexicographically",
//	   ������ݳ������ж������ֵ����������"lengths",
//	   ������ַ�ʽ���������"both"���������"none" ʾ��1 :
//	   ����
//	   3
//	   a
//	   aa
//	   bbb
//	   ���
//	   both

#include <iostream>
#include <vector>
using namespace std;

int main_1() {
	int n;
	cin >> n;

	vector<string> v;
	v.resize(n);
	for (auto &str : v) {
		cin >> str;
	}

	bool lenSym = true, lexSym = true;
	// �Ƚϳ���
	for (int i = 1; i < n; ++i) {
		if (v[i].size() < v[i - 1].size()) {
			lenSym = false;
			break;
		}
	}

	// �Ƚ�ASCII��
	for (size_t i = 1; i < v.size(); ++i) {
		if (v[i - 1] >= v[i])
		{
			lexSym = false;
			break;
		}
	}

	if (lenSym && lexSym)
		cout << "both" << endl;
	else if (!lenSym && lexSym)
		cout << "lexicographically" << endl;
	else if (lenSym && !lexSym)
		cout << "lengths" << endl;
	else if (!lenSym && !lexSym)
		cout << "none" << endl;

	return 0;
}














//   ���� : ����С������ | ʱ������ : 1�� | �ڴ����� : 32768K
//		������A��������B ����С��������ָ �ܱ�A��B��������С��������ֵ�����һ���㷨��������A��B����С ��������
//	�������� : ��������������A��B��
//	   ������� : ���A��B����С��������
//		  ʾ��1 :
//����
//5  7
//���
//35

#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	int r;
	while (r = a % b) {
		a = b;
		b = r;
	}
	return b;
}

int main()
{
	int a, b;
	while (cin >> a >> b) {
		cout << a * b / gcd(a, b) << endl;
	}
	return 0;
}