#if 0
#include <iostream>
using namespace std;

// 快速排序
void QuickSort(int * arr, int left, int right) {
	int l = left, r = right;
	if (l >= r) {
		return;
	}

	int temp = arr[l];
	while (l != r) {
		while (arr[r] >= temp && l < r) {
			r--;
		}
		while (arr[l] <= temp && l < r) {
			l++;
		}
		if (l < r) {
			int tmp = arr[l];
			arr[l] = arr[r];
			arr[r] = tmp;
		}
	}
	arr[left] = arr[l];
	arr[l] = temp;
	QuickSort(arr, left, l - 1);
	QuickSort(arr, l + 1, right);
}

// 归并排序 - 治
void merge(int* a, int l, int r, int mid) {
	int aux[100] = { 0 };

	for (int k = l; k <= r; k++) {
		aux[k - l] = a[k];
	}

	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++) {
		if (i > mid) {
			a[k] = aux[j - l];
			j++;
		}
		else if (j > r) {
			a[k] = aux[i - l];
			i++;
		}
		else if (aux[i - l] > aux[j - l]) {
			a[k] = aux[j - l];
			j++;
		}
		else {
			a[k] = aux[i - l];
			i++;
		}
	}
}

// 归并排序 - 分
void MergeSort(int * a, int l, int r) {
	if (l >= r) {
		return;
	}
	
	int mid = l + (r - l) / 2;
	MergeSort(a, l, mid);
	MergeSort(a, mid+1, r);
	merge(a, l, r, mid);
}

int main() {
	int arr[] = { 5, 4, 2, 3, 9, 8, 6, 3, 6, 7 };
	int len = sizeof(arr) / sizeof(arr[0]);

	QuickSort(arr, 0, len - 1);
	//MergeSort(arr, 0, len - 1);

	for (auto i : arr) {
		cout << i << ' ';
	}
	return 0;
}
#endif
// 驼峰转下划线
#if 0
#include <iostream>
#include <string>
using namespace std;

int main() {
	string res, s;
	while (cin >> s) {
		int len = s.size();
		res.resize(len);
		res[0] = s[0] - 'a' + 'A';
		int flag = 0;
		int count = 0;
		for (int i = 1; i < len; i++) {
			if (s[i] == '_') {
				flag = 1;
			}
			else if (flag) {
				count++;
				res[i - count] = s[i] - 'a' + 'A';
				flag = 0;
			}
			else {
				res[i - count] = s[i];
			}
		}
		cout << res << endl;
		res = '0';	// 清空res
	}
	return 0;
}
#endif

//int main() {
//	string res, s;
//	while (cin >> s) {
//		int flag = 1;
//		for (auto n : s) {
//			if (n <= 'Z' && n >= 'A' && flag) {
//				res.push_back(n - 'A' + 'a');
//				flag = 0;
//			}
//			else if (n <= 'Z' && n >= 'A' && !flag) {
//				res.push_back('_');
//				res.push_back(n - 'A' + 'a');
//			}
//			else {
//				res.push_back(n);
//			}
//		}
//		cout << res << endl;
//	}
//}

//int main() {
//	string s1, s2;
//	while (cin >> s1) {
//		int len = s1.size();
//		int flag = 1;
//		s2.resize(len*2);
//		int count = 0;
//		for (int i = 0; i < len; i++) {
//			if (s1[i] >= 'A' && s1[i] <= 'Z' && flag) {
//				flag = 0;
//				s2[i] = s1[i] - 'A' + 'a';
//			}
//			else if (s1[i] >= 'A' && s1[i] <= 'Z' && !flag) {
//				s2[i + count] = '_';
//				count++;
//				s2[i + count] = s1[i] - 'A' + 'a';
//			}
//			else {
//				s2[i + count] = s1[i];
//			}
//		}
//		cout << s2 << endl;
//	}
//
//	return 0;
//}

#if 0
#include <iostream>
#include <string>
using namespace std;

string removeKdigits(string num, int k) {
	string res;
	int n = num.size(), m = n - k;
	for (char c : num) {
		while (k && res.size() && res.back() > c) {
			res.pop_back();
			--k;
		}
		res.push_back(c);
	}
	res.resize(m);
	//去除前导0， 如10200，k = 1
	while (!res.empty() && res[0] == '0') {
		res.erase(res.begin());
	}
	return res.empty() ? "0" : res;
}

int main() {
	string s;
	int K;
	while (cin >> s >> K) {
		cout << removeKdigits(s, K) << endl;
	}

	return 0;
}
#endif

// 前N个元素逆序放到尾部
#if 0
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	while (cin >> n >> m) {
		int len = m - n;
		vector<int> v(m);
		for (int i = 0; i < m; ++i) {
			cin >> v[i];
		}

		vector<int> t(n);
		for (int i = n - 1, j = 0; i >= 0; ++j, i--) {
			t[j] = v[i];
		}
		vector<int> res(m);
		for (int i = 0; i < m; i++) {
			// 先存储未逆序的数组
			if (m-n) {
				res[i] = v[n];
				n++;
			}
			// 存储逆序的数组
			else {
				res[i] = t[i - len];
			}
		}
		for (int i = 0; i < m; i++) {
			cout << res[i] << ' ';
		}
	}
	return 0;
}
#endif
// 亲密字符串
#if 0
#include <iostream>
#include <string>
using namespace std;

bool isBroStr(string s1, string s2) {
	int len1 = s1.size(), len2 = s2.size();
	if (len1 != len2) return false;

	// s1,s2字符串相等的情况下，如果s1里面有相同的元素就为true
	if (s1 == s2) {
		for (int i = 0; i < len1; i++) {
			for (int j = i+1; j < len2; j++) {
				if (s1[i] == s1[j]) {
					return true;
				}
			}
		}
		return false;
	}
	// s1,s2不相等的情况下
	else {
		int tmp, flag = 1;
		for (int i = 0; i < len1; i++) {
			if (s1[i] != s2[i] && flag) {
				tmp = i;
				flag = 0;
			}
			else if (s1[i] != s2[i]) {
				swap(s1[i], s1[tmp]);
				if (s1 == s2)
					return true;
				else
					return false;
			}
		}
	}
	return false;
}

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		bool flag = isBroStr(s1, s2);
		if(flag)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}
#endif

// 兄弟字符串
#if 0
#include <iostream>
#include <string>
using namespace std;

bool IsBrother(string a, string b) {
	if (a.size() != b.size()) {
		return false;
	}

	int hashTable1[26] = { 0 };
	int hashTable2[26] = { 0 };
	int n = a.size();

	for (int i = 0; i < n; ++i) {
		hashTable1[a[i] - 'a']++;
		hashTable2[b[i] - 'a']++;
	}

	for (int j = 0; j < 26; ++j) {
		if (hashTable1[j] != hashTable2[j]) {
			return false;
		}
	}
	return true;
}

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		if (IsBrother(s1, s2)) {
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
	}
	return 0;
}

#endif

#if 0
#include <iostream>
using namespace std;

class A {
public:
	A() { g(); }
	~A() { cout << "~A::A() "; }
	void f() { cout << "A::f() "; }
	virtual void g() { cout << "A::g() "; }
};
class B : public A {
public:
	B() { g(); }
	~B() { cout << "~B::A() "; }
	void f() { cout << "B::f() "; }
	void g() { cout << "B::g() "; }
};

int main() {
	A* p = new B;
	p->f();
	p->g();
	delete p;
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

class Dummy {
public:
	void print() {
		cout << "hello world" << endl;
	}
};

int main() {
	Dummy* a;
	a->print();
	return 0;
}
#endif

#if 0
#include <iostream>
#include <cmath>
using namespace std;

int Ridnum(int num, int n) {
	n = pow(10, n);
	int tmp = (num % n) / (n/10);	// 得到要去掉位数的大小

	int res = (num - tmp) / n * (n/10) + num % (n / 10);

	return res;
}

bool IsRevrse(int num) {
	int temp = 0, x = num;
	while (x)
	{
		temp = (temp * 10 + x % 10);
		x = x / 10;
	}
	return num == temp ? true : false;
}
bool IsPrime(int num) {
	if (num == 0 || num == 1) {
		return false;
	}
	int n = sqrt(num);
	for (int i = 2; i <= n; ++i) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int N, M;
	int count = 0;
	while (cin >> N >> M) {
		for (int i = N; i <= M; ++i) {
			int tmp = i, len = 0;
			while (tmp) {
				tmp /= 10;
				len++;
			}
			for (int j = 1; j <= len; j++) {
				int temp = Ridnum(i, j);
				//cout << temp << endl;
				if (IsRevrse(temp) && IsPrime(temp))
					count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
#endif

// 最大公共子序列
#if 0
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
	int N;
	while (cin >> N) {
		vector<char> v1(N);
		vector<char> v2(N);
		for (int i = 0; i < N; i++) {
			cin >> v1[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> v2[i];
		}

		vector<vector<int>> dp(N + 1, vector<int>(N + 1));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (v1[i] == v2[j])
					dp[i + 1][j + 1] = dp[i][j] + 1;
				else
					dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}

		double res = (double)dp[N][N] / N;
		if (res - 0.5 > 1e-10) {
			printf("%.2f No", res);
		}
		else {
			printf("%.2f Yes", res);
		}
	}
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

int main() {
	char str[] = "hello";
	int arr[100];
	char *p1 = str;
	int* p2 = arr;
	cout << sizeof(str) << sizeof(p1) << sizeof(p2);
	return 0;
}
#endif
#if 0
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
	string s;
	getline
	while (getline(cin >> s)) {
		string res;
		res.resize(4);

		s[0] = s[0] - '0';
		s[2] = s[2] - '0';
		s[6] = s[6] - '0';
		s[8] = s[8] - '0';

		if (s[4] == '+') {
			// 调整分母至相等
			while (1) {
				if (s[2] == s[8]) {
					break;
				}
				else if (s[2] < s[8]) {
					if (s[8] % s[2] == 0) {
						int tmp = s[8] / s[2];
						s[2] *= tmp;
						s[0] *= tmp;
					}
					else {
						int tmp = s[2];
						s[2] *= s[8], s[0] *= s[8];
						s[8] *= tmp, s[6] *= tmp;
					}
				}
				else if (s[2] > s[8]) {
					if (s[2] % s[8] == 0) {
						int tmp = s[2] / s[8];
						s[8] *= tmp;
						s[6] *= tmp;
					}
					else {
						int tmp = s[2];
						s[2] *= s[8], s[0] *= s[8];
						s[8] *= tmp, s[6] *= tmp;
					}
				}
			}
			if (s[0] + s[6] == s[2]) {
				res[0] = 1;
			}
			else {
				res[0] = s[0] + s[6];
				res[1] = '/';
				res[2] = s[2];
				if (res[0] < res[2]) {
					int tmp = 0;
					for (int i = 2; i < res[0]; i++) {
						if (res[2] % i == 0 && res[0] % i == 0) {
							tmp = s[2] / i;
						}
					}
					if (tmp) {
						res[0] /= tmp, res[2] /= tmp;
					}
				}
				else if (res[0] > res[2]) {
					int tmp = 0;
					for (int i = 2; i < res[2]; i++) {
						if (res[2] % i == 0 && res[0] % i == 0) {
							tmp = s[2] / i;
						}
					}
					if (tmp) {
						s[0] /= tmp, s[2] /= tmp;
					}
				}
				res[0] += '0';
				res[2] += '0';
			}
		}
		else if (s[4] == '-') {

		}
		else if (s[4] == '*') {

		}
		else if (s[4] == '/') {

		}
		cout << res << endl;
	}
	return 0;
}
#endif

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> data(N, vector<int>(2));
	for (int i = 0; i < N; i++) {
		cin >> data[i][0] >> data[i][1];
	}
	vector<int> res(M), v(N);
	for (int i = 0; i < N; i++) {
		v[i] = data[i][0] + data[i][1] * 2;
	}

	for (int j = 0; j < M; j++) {
		int sum = 0, tmp, i;
		for (i = 0; i < N; i++) {
			if (v[i] > sum) {
				tmp = i + 1;
				sum = v[i];
			}
		}
		res[j] = tmp;
		v[tmp-1] = 0;
	}

	for (auto a : res) {
		cout << a << ' ';
	}
	return 0;
}