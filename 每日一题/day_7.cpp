//标题:合法括号序列判断
//	对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
//	给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。
//一个合法的括号串定义为 :
//   1.只包括括号字符;
//   2.左括号和右括号一一对应
//   测试样例:"(()())", 6 	返回 : true
//	测试样例 : "()a()()", 7	返回 : false
//	   测试样例 : "()(()()", 7	返回 : false

#include <iostream>
#include <stack>
using namespace std;

class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        stack<char> st;

        for (auto i : A) {
            if (i != ')') {
                st.push(i);
            }
            else if (i == ')') {
                if (st.top() != '(') {
                    return false;
                }
                else {
                    st.pop();
                }
            }
            else
                return false;
        }
        return true;
    }
};