//����:�����ǹ�
//A, B, C�������Ǻ�����, ÿ�������ﶼ��һЩ�ǹ�, ���ǲ�֪������ÿ�������Ͼ����ж��ٸ��ǹ�,
//��������֪�� ���µ���Ϣ :
//A - B, B - C, A + B, B + C.���ĸ���ֵ.ÿ����ĸ����ÿ������ӵ�е��ǹ���.
//������Ҫͨ�����ĸ���ֵ�����ÿ���������ж��ٸ��ǹ�, ��A, B, C��
//���ﱣ֤���ֻ��һ������A, B, C������ ������������
//�������� :
//����Ϊһ�У�һ��4���������ֱ�ΪA - B��B - C��A + B��B + C���ÿո������ 
//��Χ���� - 30��30֮��(������)��
//������� :
//���Ϊһ�У�����������������A��B��C��˳�����A��B��C���ÿո��������ĩ�޿ո�
//��������� ����������A��B��C�������No
//ʾ��1 :
//����
//1 -2 3 4
//���
//2 1 3

#include<iostream>
using namespace std;

int main_40() {
	int num1, num2, num3, num4;
	cin >> num1 >> num2 >> num3 >> num4;

	int A, B, C;
	//num1 + num2 == num3 - num4;
	A = (num1 + num3) / 2;
	B = (num2 + num4) / 2;
	C = B - num2;
	if (A - B == num1 && B - C == num2 && A + B == num3 && B + C == num4)
		cout << A << ' ' << B << ' ' << C << endl;
	else
		cout << "No";

	return 0;
}


//���� : ����ת��
//����һ��ʮ������M���Լ���Ҫת���Ľ�����N����ʮ������Mת��ΪN������
//�������� :
//����Ϊһ�У�M(32λ����)��N(2 �� N �� 16)���Կո������
//������� :
//Ϊÿ������ʵ�����ת���������ÿ�����ռһ�С����N����9�����Ӧ�����ֹ���ο�16����
//(���磬10 ��A��ʾ���ȵ�)
//ʾ��1 :
//����
//7 2
//���
//111

#include <iostream>
#include <string>
using namespace std;

int main() {
	string res, table = "0123456789ABCDEF";
	int M, N;
	cin >> M >> N;

	if (M < 0) {
		cout << '-';
		M = 0 - M;
	}
	while (M) {
		res.push_back(table[M % N]);
		M /= N;
	}

	for (auto i = res.size(); i > 0; i--) {
		cout << res[i - 1];
	}

	return 0;
}

#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main1()
{
	string s, table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;

	bool flag = false;
	// ����Ǹ�������ת�������������һ�� 
	if(m < 0)
	{
		m = 0 - m;
		flag = true; }
	// �����ƻ���ɶ�Ӧ���ַ���ӵ�s 
	while(m)
	{
		s += table[m % n];
		m /= n; 
	}
	if (flag)
		s += '-';

	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}