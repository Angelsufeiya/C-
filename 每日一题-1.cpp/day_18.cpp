//����:ͳ��ÿ�������ӵ�����
//	��һֻ���ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�С���ӳ����������º�ÿ��������һֻ���ӣ������� �Ӷ���������ÿ���µ���������Ϊ���� ?
//	/**
//	* ͳ�Ƴ�����������
//	*
//	* @param monthCount �ڼ����� * @return ��������
//	*/
//	public static int getTotalCount(int monthCount) {
//		return 0;
//	}
//��������:
//   ����int�ͱ�ʾmonth
//   ������� :
//   �����������int��
//   ʾ��1 :
//   ���� 9
//	   ��� 34
//

#if 0
#include <iostream>
using namespace std;

int main() {
	int month;
	while (cin >> month) {
		int first = 1;
		int second = 1;
		int result;
		for (int i = 3; i <= month; ++i) {
			result = first + second;
			second = first;
			first = result;
		}

		cout << result << endl;
	}

	return 0;
}

#endif


//���� : �ַ���ͨ���
//	�������� : �ڼ�����У�ͨ���һ�������﷨���㷺Ӧ�����ļ����������ݿ⡢������ʽ��������Ҫ�� ��λʵ���ַ���ͨ������㷨��
//	   Ҫ�� :
//ʵ������2��ͨ��� :
//	*: ƥ��0�������ϵ��ַ�(�ַ���Ӣ����ĸ������0 - 9��ɣ������ִ�Сд����ͬ)
//	? : ƥ��1���ַ�
//
//���� :
//		  ͨ������ʽ;
//		  һ���ַ�����
//		  ��� :
//		  ����ƥ��Ľ������ȷ���true���������false
//		  �������� : ������һ������ͨ������ַ�����������һ����Ҫƥ����ַ���
//			 ������� : ����ƥ��Ľ������ȷ���true���������false
//				ʾ��1 :
//		  ����
//			  te ? t*.*
//			  txt12.xls
//			  ���
//			  false

#include <iostream>
#include <string>
using namespace std;

bool match(const char* s1, const char* s2) {
	//��ǰ�ַ�����������true
	if (*s1 == '\0' && *s2 == '\0') {
		return true;
	}
	//�����ַ�����һ���Ƚ������򷵻�false
	if (*s1 == '\0' || *s2 == '\0') {
		return false;
	}

	//����?�ţ�ƥ��һ���ַ�������һ��λ��
	if (*s1 == '?') {
		return match(s1 + 1, s2 + 1);
	}
	// ����*�ţ�ƥ��0��(str��Ų��)��1��(���߶���ǰŲ��һ���ַ�)����(str��ǰŲ��һ���ַ�)
	else if (*s1 == '*') {
		return match(s1 + 1, s2) || match(s1 + 1, s2 + 1) || match(s1, s2 + 1);
	}
	else {
		if (*s1 == *s2)
			match(s1 + 1, s2 + 1);
		else
			return false;
	}
}

int main() {
	string str1, str2;
	while (cin >> str1 >> str2) {
		bool ret = match(str1.c_str(), str2.c_str());
		if (ret) {
			cout << "true" << endl;
		}
		else
			cout << "false" << endl;
	}
	return 0;
}