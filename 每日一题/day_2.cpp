//标题:排序子序列
//牛牛定义排序子序列为一个数组中一段连续的子序列, 并且这段子序列是非递增或者非递减排序的。
//牛牛有一 个长度为n的整数数组A, 他现在有一个任务是把数组A分为若干段排序子序列, 
//
//牛牛想知道他最少可以把这个数 组分为几段排序子序列.
//如样例所示, 牛牛可以把数组A划分为[1, 2, 3]和[2, 2, 1]两个排序子序列, 
//至少需要划分为2个排序子序列, 所以输出 
//	2
//输入描述 :
//	 输入的第一行为一个正整数n(1 ≤ n ≤ 10 ^ 5)
//	 第二行包括n个整数A_i(1 ≤ A_i ≤ 10 ^ 9), 表示数组A的每个数字。 
//输出描述 : 输出一个整数表示牛牛可以将A最少划分为多少段排序子序列 
//	示例1 :
//	输入
//	    6
//		1 2 3 2 2 1 
//	输出
//	   2

#include <iostream>
#include <vector>
using namespace std;

//int main() {
//    int n;
//    cin >> n;
//
//    // 注意这里多给了一个值，是处理越界的情况的比较
//    vector<int> a;
//    a.resize(n + 1);
//    a[n] = 0;
//    
//    //读入数组
//    int i = 0;
//    for (i = 0; i < n; ++i)
//        cin >> a[i];
//    i = 0;
//
//    int count = 0;
//    while (i < n)
//    {
//        // 非递减子序列
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
//        else // 非递增子序列 
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
		// 当前数字与下一个数字相等，则跳过
		if (A_i[i] == A_i[i + 1]) {
			continue;
		}
		else {
			// 若发生跳变，计数+1，指针+1。
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



//标题:倒置字符串
//将一句话的单词进行倒置，标点不倒置。比如 I like beijing.经过函数后变为 : beijing.like I
//
//输入描述 :
//每个测试输入包含1个测试用例 : I like beijing.输入用例长度不超过100 输出描述 :
//依次输出倒置之后的字符串, 以空格分割
//示例1 :
//输入
//	I like beijing.
//输出
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
	// 注意这里要使用getline，cin>>s遇到空格就接收结束了 
	getline(cin, s);
	// 翻转整个句子 
	reverse(s.begin(), s.end());
	// 翻转单词
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