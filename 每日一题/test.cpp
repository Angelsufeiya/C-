//����:�滻�ո�
//��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20����
//���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��

//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//using namespace std;
//#include <string>

//class Solution {
//public:
//	void replaceSpace(char *str, int length) { // ����ո�ĸ���
//		int space_num = 0;
//		for (int i = 0; i < length; ++i)
//		{
//			if (str[i] == ' ')
//				space_num++;
//		}
//		// �Ӻ���ǰ������Ų���ַ��������ո��滻Ϊ%20 
//		for(int i = length-1; i >= 0; --i)
//		{
//			if (str[i] == ' ')
//			{
//				space_num--;
//				str[i + space_num * 2] = '%';
//				str[i + space_num * 2 + 1] = '2';
//				str[i + space_num * 2 + 2] = '0';
//			}
//			else
//			{
//				str[i + space_num * 2] = str[i];
//			} 
//		}
//	}
//};

//����һ���ַ�����������ַ����������ַ�����
//�������� :
//ÿ����������һ���ַ������ַ�����󳤶�Ϊ100����ֻ������ĸ��������Ϊ�մ������ִ�Сд��
//������� :
//ÿ������һ�У����ַ���ԭ�е��ַ�˳������ַ����ϣ����ظ����ֲ��������ĸ�������
//
//#include <iostream>
//using namespace std;

//int main_0() {
//	string s;
//	cin >> s;
//	char str[256] = { 0 };
//
//	for (int i = 0; i < s.size(); ++i) {
//		if (!str[s[i]]) {
//			cout << s[i];
//		}
//		str[s[i]] = 1;
//	}
//
//	return 0;
//}

//��һ���Ź�������飬����n����������������������������һ�����ȵ���λ��
//���磬ԭ����Ϊ[1, 2, 3, 4, 5, 6]��������λ5��λ�ü������[6, 1, 2, 3, 4, 5], 
//���ڶ�����λ������飬��Ҫ����ĳ��Ԫ�ص�λ�á������һ�����Ӷ�Ϊlog������㷨����������
//����һ��int����A��Ϊ��λ������飬ͬʱ���������Сn����Ҫ���ҵ�Ԫ�ص�ֵx��
//�뷵��x��λ��(λ�ô��㿪ʼ)����֤������Ԫ�ػ��졣



#include <iostream>
#include <set>
using namespace std;

int main()
{
	int n;
	cin >> n;
	multiset<int> data;

	int sum = 0;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		data.insert(tmp);
	}
	while (data.size() > 1)
	{
		tmp = 0;
		tmp += *data.begin();
		data.erase(data.begin());
		tmp += *data.begin();
		data.erase(data.begin());
		data.insert(tmp);
		sum += tmp;
	}
	cout << sum;
	return 0;
}


#include <iostream>
#include <set>

using namespace std;
int luogu1090()
{
	int n;
	cin >> n;
	multiset<int> data;
	multiset<int>::iterator is;
	int sum = 0;
	int i;
	int tmp;
	for (i = 0; i < n; i++)
	{
		cin >> tmp;
		data.insert(tmp);
	}
	while (data.size() > 1)
	{
		tmp = 0;
		is = data.begin();
		tmp += *is;
		data.erase(is);
		is = data.begin();
		tmp += *is;
		data.erase(is);
		data.insert(tmp);
		sum += tmp;
	}
	cout << sum;
	return 0;
}
