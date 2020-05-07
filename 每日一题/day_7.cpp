//����:�Ϸ����������ж�
//	����һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ���
//	����һ���ַ���A�����ĳ���n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���
//һ���Ϸ������Ŵ�����Ϊ :
//   1.ֻ���������ַ�;
//   2.�����ź�������һһ��Ӧ
//   ��������:"(()())", 6 	���� : true
//	�������� : "()a()()", 7	���� : false
//	   �������� : "()(()()", 7	���� : false

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