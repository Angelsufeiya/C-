//����:��Ҫ��
//����С����һ��W*H��������ӣ�������б��Ϊ0~H - 1��������б��Ϊ0~W - 1��
//ÿ������������Է�һ �鵰�⣬�������鵰���ŷ����þ��벻�ܵ���2��
//����������������(x1, y1), (x2, y2)��ŷ����þ���Ϊ 
//((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) ������ƽ����
//С����֪�������ԷŶ��ٿ鵰������������ 
//�������� :
//ÿ������������񳤿�W, H���ÿո�ָ�.(1 �� W��H �� 1000) 
//������� :
//���һ�������Էŵĵ�����
//ʾ��1: 
//���� 
//3 2 
//���
//4

#include<iostream>
#include<vector>
using namespace std;

int main_1(){
	int W, H, res = 0;
	cin >> W >> H;	// H ��ʾ�У� W ��ʾ��

	// ֱ�ӱ������㣬Ĭ�����е����λ�ñ�ǳ�1,���ܷŵĵط���ǳ�0
	vector<vector<int>> vv;
	vv.resize(H);
	for (auto& e : vv)
		e.resize(W, 1);

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (vv[i][j] == 1)
			{
				res++;
				// ��ǲ��ܷŵ����λ�� 
				if ((i + 2) < H)
					vv[i + 2][j] = 0;
				if ((j + 2) < W)
					vv[i][j + 2] = 0;
			}
		}
	}
	cout << res;
	
	return 0;
}

// Ĭ�����е����λ�ñ�ǳ�1,���ܷŵĵط���ǳ�0 
// 1 1 0 0 1 1
// 1 1 0 0 1 1
// 0 0 1 1 0 0
// 0 0 1 1 0 0

#include <iostream>
using namespace std;

int main_2()
{
	int a, b;

	cin >> a >> b;

	int x, y;

	int suba = 4 - (a % 4 ? a % 4 : 4);	// ���� suba Ϊ4�ı���
	int subb = 4 - (b % 4 ? b % 4 : 4);	// ��� subb Ϊ4�ı���
	x = a + suba;	// ʹ x �ڼ���suba��Ϊ4�ı���
	y = b + subb;	// ʹ y �ڼ���subb��Ϊ4�ı���

	int sum = x * y / 2;	// ���㳤��������4�ı�����sum�Ĵ�С

	sum -= suba * (x / 2) + subb * (y / 2);	// ��ȥ���ݵĳ�����һ�룬����������ɶ��ȥ��������

	if (suba == 0 || subb == 0)	// �����߿�ֻҪ��һ����4�ı���������������ʽ�󣬿�ֱ�����
	{
		//do nothing
	}
	else if (suba == 1 && subb == 1)
	{
		sum++;	// ʾ�� �����Ϊ3��
	}
	else if (suba == 1 || subb == 1)
	{
		sum += 2;	// ʾ�� ��3����2
	}
	else if (suba == 3 && subb == 3)
	{
		sum += 5;	// ʾ�� ��1����1
	}
	else 
	{
		sum += 4;
	}

	cout << sum;

	return 0;
}



//����:���ַ���ת��������
//��һ���ַ���ת����һ������(ʵ��Integer.valueOf(string)�Ĺ��ܣ�
//����string����������Ҫ��ʱ����0)��Ҫ�� ����ʹ���ַ���ת�������Ŀ⺯���� 
//��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0��
//��������: 
//����һ���ַ���, ����������ĸ����, ����Ϊ�� 
//������� : 
//����ǺϷ�����ֵ����򷵻ظ����֣����򷵻�0 
//ʾ��1 :
//����
//+2147483647
//1a33
//���
//2147483647
//0

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int StrToInt(string str) {
		if (str.empty())
			return 0;

		int symbol;
		if (str[0] == '+') {
			symbol = 1;
			str[0] = '0';
		}

		if (str[0] == '-') {
			symbol = -1;
			str[0] = '0';
		}

		int res = 0;
		if (str[0] >= '0' && str[0] <= '9') {
			for (auto e : str) {
				if (e < '0' || e > '9') {
					return 0;
				}
				else {
					res = res * 10 + e - '0';
				}
			}
		}

		return symbol * res;
	}
};

int main_3() {
	Solution s;
	string ss;
	cin >> ss;
	s.StrToInt(ss);

	return 0;
}