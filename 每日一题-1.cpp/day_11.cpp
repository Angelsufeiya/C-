//标题:最近公共祖先
//有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，根结点编号为1。现在有两个结点 a，b。
//请设计一个算法，求出a和b点的最近公共祖先的编号。
//给定两个int a, b。为给定结点的编号。请返回a和b的最近公共祖先的编号。注意这里结点本身也可认为是其祖 先。
//测试样例 : 2，3
//   返回 : 1
class LCA {
public:
    int getLCA(int a, int b) {
        while (a != b) {
            if (a > b) {
                a /= 2;
            }
            else {
                b /= 2;
            }
        }
        return a;
    }
};

//
//	标题 : 求最大连续bit数
//	 功能 : 求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1
//	  输入 : 一个byte型的数字
//	   输出 : 无
//		返回 : 对应的二进制数字中1的最大连续数
//		 输入描述 : 输入一个byte数字
//			输出描述 : 输出转成二进制之后连续1的个数

#include <iostream>
using namespace std;

int main() {
    int num;
    while (cin >> num) {
        int sum = 1, count = 0;

        while (num) {
            //获取当前位的二进制值 
            if (num & 1)
            {
                //如果1的值连续，计数累加，并且跟新最大计数 
                ++count;
                if (count > sum) {
                    sum = count;
                }
            }
            else{
                count = 0;
            }
            //右移一次，为获取下一位二进制值做准备
            num = num >> 1;

            /*if (num % 2) {
                count++;
                if (count > sum) {
                    sum = count;
                }
            }
            else {
                count = 0;
            }
            num /= 2;*/
        }
        cout << sum << endl;
    }

    return 0;
}




#include <iostream>
#include <vector>
using namespace std;

int main() {
    int row, col;
    cin >> row >> col;

    vector<vector<int>> vv;
    vv.resize(row);
    for (auto &i : vv) {
        i.resize(col, '■');
    }
    
    //设置雷数

    return 0;
}