//标题:计算日期到天数转换
//	根据输入的日期，计算是这一年的第几天。。
//详细描述 : 输入某年某月某日，判断这一天是这一年的第几天 ?
//   接口设计及说明 :
//		   /***************************************************************************** Description : 数据转换
//		   Input Param : year 输入年份
//		   Month 输入月份 Day 输入天
//		   Output Param :
//		   Return Value : 成功返回0，失败返回-1(如:数据错误) *****************************************************************************/ public static int iConverDateToDay(int year, int month, int day)
//{
//			   /* 在这里实现功能，将结果填入输入数组中*/
//			   return 0;
//		   }
//   /***************************************************************************** Description :
//   Input Param :
//   Output Param :
//   Return Value : 成功:返回outDay输出计算后的第几天;
//   失败:返回-1 *****************************************************************************/
//   public static int getOutDay() {
//	   return 0;
//   }
//输入描述:
//   输入三行，分别是年，月，日
//   输出描述 : 成功：返回outDay输出计算后的第几天;
//   失败：返回 - 1
//   示例1: 输入 2012
//		12 31
//		输出
//		366
//
#include <iostream>
#include <vector>
using namespace std;

int iConverDateToDay(int year, int month, int day)
{
    if (month > 12 || month < 0) {
        return -1;
    }

    vector<int> v = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (year < 0) {
        year = 0 - year;
    }
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
        v[2] = 29;
    }

    if (day > v[month] || day < 0) {
        return -1;
    }

    int sum = 0;
    for (int i = 1; i < month; i++) {
        sum += v[i];
    }
    return sum + day;
}

int main_15() {
    int year, month, day;
    while (cin >> year >> month >> day) {
        cout << iConverDateToDay(year, month, day) << endl;
    }
    return 0;
}
//
//	标题 : 幸运的袋子
//		 一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。如果一个袋子是幸运的当 且仅当所有球的号码的和大于所有球的号码的积。
//	 例如 : 如果袋子里面的球的号码是{ 1, 1, 2, 3 }，这个袋子就是幸运的，因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
//		  你可以适当从袋子里移除一些球(可以移除0个, 但是别移除完)，要使移除后的袋子是幸运的。现在让你编程计 算一下你可以获得的多少种不同的幸运的袋子。
//	  输入描述 :
//   第一行输入一个正整数n(n ≤ 1000)
//	   第二行为n个数正整数xi(xi ≤ 1000) 输出描述 : 输出可以产生的幸运的袋子数 示例1 :
//   输入
//	   3
//	   1 1 1
//	   输出
//	   2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
    getLuckyPacket:从当前位置开始搜索符合要求的组合，一直搜索到最后一个位置结束 
    v: 袋子中的所有球
    n: 球的总数
    pos: 当前搜索的位置
    sum: 到目前位置的累加和
    mul: 到目前位置的累积值 
*/
int getLuckyPacket(vector<int> v, int n, int pos, int sum, int mul) {
    int count = 0; 
    //循环，搜索以位置i开始所有可能的组合 
    for (int i = pos; i<n; i++)
    {
        sum += v[i];
        mul *= v[i];
        if (sum > mul)
        {
            //找到符合要求的组合，加1，继续累加后续的值，看是否有符合要求的集合
            count += 1 + getLuckyPacket(v, n, i + 1, sum, mul);
        }
        else if (v[i] == 1)
        {
            //如何不符合要求，且当前元素值为1，则继续向后搜索
            count += getLuckyPacket(v, n, i + 1, sum, mul);
        }
        else
        {
            //如何sum大于multi,则后面就没有符合要求的组合了
            break;
        }
        //要搜索下一个位置之前，首先恢复sum和multi
        sum -= v[i];
        mul /= v[i]; 
        //数字相同的球，没有什么区别，都只能算一个组合，所以直接跳过 
        while (i < n - 1 && v[i] == v[i + 1])
        {
            i++;
        } 
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> v;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    cout << getLuckyPacket(v, n, 0, 0, 1) << endl;

    return 0;
}