//����:ͳ�ƻ���
//�����Ĵ�����һ�������ͷ�����һ�����ַ��������硰level�����ߡ�noon���ȵȾ��ǻ��Ĵ���
//�����ǳ�ϲ������ӵ�� �Գ����Ļ��Ĵ������յ�ʱ�����õ���������ֱ����ַ���A���ַ���B��
//�������ǳ�������û�а취���ַ� ��B�����ַ���Aʹ�������ַ�����һ�����Ĵ���
//����ܻ��������󣬰�����Ѱ���ж����ֲ���취����ʹ�� ����һ�����Ĵ���
//����ַ���B�����λ�ò�ͬ�Ϳ���Ϊ��һ���İ취��
//���� :
//A = ��aba����B = ��b����������4�ְ�B����A�İ취 : *��A�ĵ�һ����ĸ֮ǰ : "baba" ���ǻ���
//*�ڵ�һ����ĸ��a��֮�� : "abba" �ǻ���
//*����ĸ��b��֮�� : "abba" �ǻ���
//*�ڵڶ�����ĸ'a'֮�� "abab" ���ǻ���
//�������������Ĵ�Ϊ2
//�������� :
//ÿ���������ݹ����С�
//��һ��Ϊ�ַ���A
//�ڶ���Ϊ�ַ���B
//�ַ������Ⱦ�С��100��ֻ����Сд��ĸ
//������� :
//���һ�����֣���ʾ���ַ���B�����ַ���A֮�󹹳�һ�����Ĵ��ķ�����
//ʾ��1 :
//����
//aba
//b
//���
//2

#include <iostream>
using namespace std;

bool IsCircleText(const string& s) {
	size_t begin = 0;
	size_t end = s.size() - 1;
	for (; begin < end; begin++,end--) {
		if (s[begin] != s[end]) {
			return false;
		}
	}
	return true;
}

int main_51() {
	string str1, str2;
	int count = 0;
	cin >> str1 >> str2;

	for (int i = 0; i <= str1.size(); i++) {
		string str = str1;
		str.insert(i, str2);
		if (IsCircleText(str))
			count++;
	}
	cout << count << endl;

	return 0;
}





//����:��������
//һ�������� N ��Ԫ�أ�����������������͡� 
//���� : [-1, 2, 1]������������������Ϊ[2, 1]�����Ϊ 3 
//�������� :
//����Ϊ���С� ��һ��һ������n(1 <= n <= 100000)��
//��ʾһ����n��Ԫ�� �ڶ���Ϊn��������ÿ��Ԫ��, ÿ�� ��������32λint��Χ�ڡ��Կո�ָ���
//������� :
//���������������к�����ֵ��
//ʾ��1 :
//����
//3 -1 2 1
//���
//3
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> array;
    array.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int sum = array[0];    //�����ۼ�
    int tmp = array[0];    //������¼���������

    for (size_t i = 1; i < array.size(); i++) {
        if (sum >= 0) {
            sum += array[i];
        }
        else {
            sum = array[i];
        }
        if (sum > tmp) {
            tmp = sum;
        }
    }
    cout << tmp;

    return 0;
}
