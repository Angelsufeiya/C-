//标题:二进制插入
//	有两个32位整数n和m，请编写算法将m的二进制数位插入到n的二进制的第j到第i位, 其中二进制的位数从低位 数到高位且以0开始。
//	给定两个数int n和int m，同时给定int j和int i，意义如题所述，请返回操作后的数，保证n的第j到第i位均为 零，且m的二进制位数小于等于i - j + 1。
//测试样例 : 1024，19，2，6
//   返回 : 1100

class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        m <<= j;
        return n | m;
    }
};

//
//	标题 : 查找组成一个偶数最接近的两个素数
//		 任意一个偶数(大于2)都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出组成指定
//		 偶数的两个素数差值最小的素数对
//	 输入描述 :
//   输入一个偶数
//   输出描述 : 输出两个素数
//	  示例1 : 输入 20
//			输出
//			7 13

#include <iostream>
#include <math.h>
using namespace std;

// 判断素数
bool IsPrime(int n) {
    // 只遍历到开方出，不能被开方左边的数整除，则一定不能被开方右边的数整除
    for (int i = 2; i <= sqrt(n); i++) {
        if (!(n % i)) {
            return false;
        }
    }
    return true;

}

int main() {
    int num;
    while (cin >> num) {
        int p1, p2;
        p1 = p2 = num / 2;

        for (; p1 > 0, p2 <= num;) {
            if (IsPrime(p1)) {
                if (IsPrime(p2)) {
                    if (p1 + p2 == num) {
                        break;
                    }
                    else if (p1 + p2 > num) {
                        --p1;
                    }
                    else if (p1 + p2 < num) {
                        ++p2;
                    }
                }
                else {
                    ++p2;
                }
            }
            else {
                --p1;
            }
        }

        cout << p1 << endl << p2 << endl;
    }

    return 0;
}