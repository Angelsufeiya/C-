//����:����������
//ţţ��������������Ϊһ��������һ��������������, ��������������Ƿǵ������߷ǵݼ�����ġ�
//ţţ��һ ������Ϊn����������A, ��������һ�������ǰ�����A��Ϊ���ɶ�����������, 
//
//ţţ��֪�������ٿ��԰������ ���Ϊ��������������.
//��������ʾ, ţţ���԰�����A����Ϊ[1, 2, 3]��[2, 2, 1]��������������, 
//������Ҫ����Ϊ2������������, ������� 
//	2
//�������� :
//	 ����ĵ�һ��Ϊһ��������n(1 �� n �� 10 ^ 5)
//	 �ڶ��а���n������A_i(1 �� A_i �� 10 ^ 9), ��ʾ����A��ÿ�����֡� 
//������� : ���һ��������ʾţţ���Խ�A���ٻ���Ϊ���ٶ����������� 
//	ʾ��1 :
//	����
//	    6
//		1 2 3 2 2 1 
//	���
//	   2

#include <iostream>
#include <vector>
using namespace std;

//int main() {
//    int n;
//    cin >> n;
//
//    // ע����������һ��ֵ���Ǵ���Խ�������ıȽ�
//    vector<int> a;
//    a.resize(n + 1);
//    a[n] = 0;
//    
//    //��������
//    int i = 0;
//    for (i = 0; i < n; ++i)
//        cin >> a[i];
//    i = 0;
//
//    int count = 0;
//    while (i < n)
//    {
//        // �ǵݼ�������
//        if (a[i] < a[i + 1]) {
//            while (i < n && a[i] <= a[i + 1])
//                i++;
//
//            count++;
//            i++;
//        }
//        else if (a[i] == a[i + 1])
//        {
//            i++;
//        }
//        else // �ǵ��������� 
//        {
//            while (i < n && a[i] >= a[i + 1])
//                i++;
//
//            count++;
//            i++;
//        }
//    }
//    cout << count << endl;
//
//    return 0;
//}




bool isChange(int previous, int current, int next) {
	if ((current > previous && current > next) || (current < previous && current < next)) {
		return true;
	}
	return false;
}

int main_1() {
	int n;
	cin >> n;

	if (n < 3) 
		cout << "1" << endl;

	vector<int> A_i;
	for (int i = 0, tep; i < n; i++)
	{
		cin >> tep;
		A_i.push_back(tep);
	}

	int count = 1, previous = 0;
	for (int i = 1; i < n - 1; i++) {
		// ��ǰ��������һ��������ȣ�������
		if (A_i[i] == A_i[i + 1]) {
			continue;
		}
		else {
			// ���������䣬����+1��ָ��+1��
			if (isChange(A_i[previous], A_i[i], A_i[i + 1])) {
				count++;
				previous = ++i;
			}
			else {
				previous = i - 1;
			}
		}
	}
	cout << count << endl;

	return 0;
}



//#include <iostream>
//using namespace std;
//
//int main() {
//	int a[] = { 1,2,3,4 }; 
//	int* b = a;
//	*b += 2; 
//	*(b + 2) = 2;
//	b++; 
//	printf(" %d, %d\n", *b, *(b + 2));
//
//	return 0;
//}



//����:�����ַ���
//��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing.�����������Ϊ : beijing.like I
//
//�������� :
//ÿ�������������1���������� : I like beijing.�����������Ȳ�����100 ������� :
//�����������֮����ַ���, �Կո�ָ�
//ʾ��1 :
//����
//	I like beijing.
//���
//	beijing.like I

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string str;
	getline(cin, str);

	int start = 0;
	int end = str.size() - 1;
	
	for (start = 0; start < end; start++, end--) {
		swap(str[start], str[end]);
	}

	end = 0;

	while (end != str.size()) {
		start = end;
		while (str[end] != ' ' && end != str.size()) {
			end++;
		}

		int tmp;
		if (end != str.size()) {
			tmp = end + 1;
		}
		else {
			tmp = end;
		}

		--end;
		for (; start < end; start++, end--) {
			swap(str[start], str[end]);
		}
		end = tmp;
	}
	
	cout << str << endl;

	return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	// ע������Ҫʹ��getline��cin>>s�����ո�ͽ��ս����� 
	getline(cin, s);
	// ��ת�������� 
	reverse(s.begin(), s.end());
	// ��ת����
	auto start = s.begin();
	while (start != s.end()) {
		auto end = start;
		while (end != s.end() && *end != ' ')
			end++;
		reverse(start, end);
		if (end != s.end())
			start = end + 1;
		else
			start = end;
	}
	cout << s << endl;

	return 0;
}