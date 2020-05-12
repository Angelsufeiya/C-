//����:����ӷ�
//	���дһ��������������������ӡ�����ʹ�� + �����������������
//
//	1, 2
//���� : 3
//

#include <iostream>
using namespace std;

int main_1() {
	int A, B;
	cin >> A >> B;

	cout << A + B << endl;

	int sum = 0, carry = 0;
	while (B != 0) {
		//��Ӧλ�ĺ�
		sum = A ^ B;
		//��Ӧλ�͵Ľ�λ����Ȼ�ǽ�λ����Ҫ��������һλ 
		carry = (A & B) << 1;
		A = sum;
		B = carry;
	}
	cout << sum;
	return 0;
}


class UnusualAdd {
public:
	int addAB(int A, int B) {
		int sum = 0, carry = 0;
		while (B != 0) {
			//��Ӧλ�ĺ�
			sum = A ^ B;
			//��Ӧλ�͵Ľ�λ����Ȼ�ǽ�λ����Ҫ��������һλ 
			carry = (A & B) << 1;
			A = sum;
			B = carry;
		}
		return sum;
	}
};


//
// ����:201301 JAVA ��Ŀ2 - 3��
//	���дһ������(���������Ӻ���)������n x m�����̸���(nΪ����ĸ�������mΪ����ĸ�����)���Ÿ� 
//�Ա�Ե�ߴ����Ͻ��ߵ����½ǣ��ܹ��ж������߷���Ҫ�����߻�ͷ·��
//�� : ֻ�����Һ������ߣ��������� �������ߡ�
//�������� :
//   ��������������
//   ������� : ���ؽ��
//	  ʾ��1 :
//   ����
//	   2
//	   2
//	   ���
//	   6


#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<vector<int>> vv;

	int n, m;
	cin >> n >> m;
	vv.resize(m+1);
	for (auto& a : vv) {
		a.resize(n+1, 1);
	}

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			vv[i][j] = vv[i - 1][j] + vv[i][j - 1];
		}
	}

	cout << vv[m][n] << endl;

	return 0;
}

#include<iostream>
using namespace std;

int pathNum(int n, int m)
{
	if (n > 1 && m > 1)
		//�ݹ�
		return pathNum(n - 1, m) + pathNum(n, m - 1);
	else if (((n >= 1) && (m == 1)) || ((n == 1) && (m >= 1))) 
		//��ֹ����
		return n + m;
	else
		//����Ϊ0ʱ�� ·��Ϊ0
		return 0;
}
int main() {
	int n, m;
	while (cin >> n >> m)
	{
		cout << pathNum(n, m) << endl;
	}
	return 0;
}