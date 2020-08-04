//标题:统计每个月兔子的总数
//	有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，假如兔 子都不死，问每个月的兔子总数为多少 ?
//	/**
//	* 统计出兔子总数。
//	*
//	* @param monthCount 第几个月 * @return 兔子总数
//	*/
//	public static int getTotalCount(int monthCount) {
//		return 0;
//	}
//输入描述:
//   输入int型表示month
//   输出描述 :
//   输出兔子总数int型
//   示例1 :
//   输入 9
//	   输出 34
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


//标题 : 字符串通配符
//	问题描述 : 在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。现要求 各位实现字符串通配符的算法。
//	   要求 :
//实现如下2个通配符 :
//	*: 匹配0个或以上的字符(字符由英文字母和数字0 - 9组成，不区分大小写。下同)
//	? : 匹配1个字符
//
//输入 :
//		  通配符表达式;
//		  一组字符串。
//		  输出 :
//		  返回匹配的结果，正确输出true，错误输出false
//		  输入描述 : 先输入一个带有通配符的字符串，再输入一个需要匹配的字符串
//			 输出描述 : 返回匹配的结果，正确输出true，错误输出false
//				示例1 :
//		  输入
//			  te ? t*.*
//			  txt12.xls
//			  输出
//			  false

#include <iostream>
#include <string>
using namespace std;

bool match(const char* s1, const char* s2) {
	//当前字符结束，返回true
	if (*s1 == '\0' && *s2 == '\0') {
		return true;
	}
	//两个字符串有一个先结束，则返回false
	if (*s1 == '\0' || *s2 == '\0') {
		return false;
	}

	//遇到?号，匹配一个字符，跳过一个位置
	if (*s1 == '?') {
		return match(s1 + 1, s2 + 1);
	}
	// 遇到*号，匹配0个(str不挪动)，1个(两者都向前挪动一个字符)或多个(str向前挪动一个字符)
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