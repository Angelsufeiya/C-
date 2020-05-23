//����:��������
//�������������������� :
//xcopy / s c : \ d : \��
//������������ :
//����1 : ������xcopy
//����2 : �ַ��� / s
//  ����3 : �ַ���c : \
//	����4 : �ַ���d : \ ���дһ��������������ʵ�ֽ������и�����������������
//	  �������� :
//1.�����ָ���Ϊ�ո� 2.�����á������������Ĳ���������м��пո񣬲��ܽ���Ϊ�������������������������
//xcopy /s ��C : \program files�� ��d : \��ʱ��������Ȼ��4������3������Ӧ�����ַ���C : \program files�������� C : \program��ע���������ʱ����Ҫ������ȥ�������Ų�����Ƕ�������
//3.����������
//4.������������֤��������ֲ�����Ҫ�������
//�������� :
//����һ���ַ����������пո�
//������� : ��������������ֽ��Ĳ�����ÿ����������ռһ��
//   ʾ��1 :
//����
//xcopy /s c : \\ d:\\
//���
//4
//xcopy
// /s
//c : \\
//d:\\
//
//

#include <iostream>
#include <string>
using namespace std;

int main_13() {
	string s;
	getline(cin, s);

	int count = 1;

	int i;
	for (i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			++count;
			s[i] = '\n';
		}
		//�����˫���ţ���������ֱ����һ��˫���Ž��� 
		if (s[i] == '"')
		{
			do
			{
				s[i] = s[i + 1];
				i++;
			} while (s[i] != '"');
			s[i - 1] = s[i] = ' ';
		}
	}

	std::cout << count << endl;
	std::cout << s << endl;

	return 0;
}

//
//
//����:��ʯ��
//С��������һ��ʯ��·ǰ��ÿ��ʯ���ϴ�1���ű��Ϊ : 1��2��3.......����ʯ��·Ҫ��������Ĺ������ǰ�� : ����С�׵�ǰ���ڵı��ΪK�� ʯ�壬С�׵���ֻ����ǰ��K��һ�� Լ��(����1��K)����������K + X(XΪK��һ����1�ͱ����Լ��)��λ�á� С�׵�ǰ���ڱ��ΪN��ʯ�壬���� �������ǡ��ΪM��ʯ��ȥ��С����֪��������Ҫ��Ծ���ο��Ե��
//					   ���� :
//N = 4��M = 24 :
//4->6->8->12->18->24
//����С��������Ҫ��Ծ5�Σ��Ϳ��Դ�4��ʯ������24��ʯ��
//�������� :
//����Ϊһ�У�����������N��M���Կո������(4 �� N �� 100000) (N �� M �� 100000) ������� :
//���С��������Ҫ��Ծ�Ĳ���, ������ܵ������ -1
//ʾ��1 :
//	����
//	4 24
//	���
//	5

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ����Լ���������1�ͱ����Լ��
void divisorNum(int n, vector<int> &divNum) {
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0) {
			divNum.push_back(i); 
			// ��ƽ����ʱ������һ����ҲҪ���� 
			if (n / i != i)
				divNum.push_back(n / i);
		}
	}
}

int Jump(int N, int M) {
	// ����ĵ����stepNum��Ĳ�������ʼNΪ1������N��NΪ1�� 
	vector<int> stepNum(M + 1, 0);
	stepNum[N] = 1;

	for (int i = N; i < M; i++)
	{
		// N������Լ������Ϊ�ӱ�������㿪ʼ���ߵ����� 
		vector<int> divNum;

		// 0��������㲻�ܵ�
		if (stepNum[i] == 0)
			continue; 
		
		// ����������ߵĲ���������divNum��������
		divisorNum(i, divNum);

		for (int j = 0; j < divNum.size(); j++)
		{
			//��λ��i�����ܵ���ĵ�Ϊ stepNum[divNum[j]+i]
			if ((divNum[j] + i) <= M && stepNum[divNum[j] + i] != 0)
				stepNum[divNum[j] + i] = min(stepNum[divNum[j] + i], stepNum[i] + 1);
			else if ((divNum[j] + i) <= M)
				stepNum[divNum[j] + i] = stepNum[i] + 1;
		}
	}

	if (stepNum[M] == 0)
		return -1;
	else
		//��ʼ��ʱ�����һ��������Ҫ��1 
		return stepNum[M] - 1;
}

int main() {
	int N, M;
	cin >> N >> M;

	cout << Jump(N, M) << endl;

	return 0;
}