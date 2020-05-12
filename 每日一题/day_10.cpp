//����:������
//	����һ�������ľ��������̣������һ����Ч�㷨�жϵ�ǰ����Ƿ��ʤ��
//	����һ����ά����board������ǰ���̣�����Ԫ��Ϊ1�Ĵ����ǵ�ǰ��ҵ����ӣ�Ϊ0��ʾû�����ӣ�Ϊ - 1�� ���ǶԷ���ҵ����ӡ�
//�������� :
//   [[1, 0, 1], [1, -1, -1], [1, -1, 0]]
//���� : true
//
#include <iostream>
#include <vector>
using namespace std;
class Board {
public:
    bool checkWon(vector<vector<int>> board) {
        int row = board.size();
        int i, j, sum;

        //���ÿһ�еĺ����Ƿ����row 
        for (i = 0; i < row; i++) {
            sum = 0;
            for (j = 0; j < row; j++)
            {
                sum += board[i][j];
            }
            if (sum == row)
                return true;
        }

        // ���ÿһ�еĺ����Ƿ����row 
        for (j = 0; j < row; j++) {
            sum = 0;
            for (i = 0; i < row; i++)
            {
                sum += board[i][j];
            }
            if (sum == row)
                return true;
        }

        //������Խ��ߵĺ����Ƿ����row
        sum = 0;
        for (i = 0; i < row; i++) {
            sum += board[i][i];
        }
        if (sum == row)
            return true;

        //��鸱�Խ��ߵĺ����Ƿ����row
        sum = 0;
        for (i = 0; i < row; i++) {
            sum += board[i][row - 1 - i];
        }
        if (sum == row)
            return true;

        // ���������������
        return false;

    }
};
//
//����:����ǿ�ȵȼ� | ʱ������ : 1�� | �ڴ����� : 32768K ���밴���¹�����мƷ֣������ݲ�ͬ�ĵ÷�Ϊ������а�ȫ�ȼ����֡�
//һ�����볤�� :
//   5 �� : С�ڵ���4 ���ַ�
//	   10 �� : 5 ��7 �ַ�
//	   25 �� : ���ڵ���8 ���ַ� 
//������ĸ :
//   0 �� : û����ĸ
//	   10 �� : ȫ����С(��)д��ĸ 
//     20 �� : ��Сд�����ĸ �������� :
//   0 �� : û������
//	   10 �� : 1 ������
//	   20 �� : ����1 ������ �ġ����� :
//   0 �� : û�з���
//	   10 �� : 1 ������
//	   25 �� : ����1 ������
//   �塢���� :
//   2 �� : ��ĸ������
//	   3 �� : ��ĸ�����ֺͷ���
//	   5 �� : ��Сд��ĸ�����ֺͷ��� �������ֱ�׼ :
//   >= 90 : �ǳ���ȫ
//	   >= 80 : ��ȫ(Secure) >= 70 : �ǳ�ǿ
//	   >= 60 : ǿ(Strong)
//	   >= 50 : һ��(Average) >= 25 : ��(Weak)
//	   >= 0 : �ǳ���
//   ��Ӧ���Ϊ :
//   VERY_WEAK, WEAK, AVERAGE, STRONG, VERY_STRONG, SECURE,
//	   VERY_SECURE
//	   ���������������ַ��������а�ȫ������ ע :
//��ĸ : a - z, A - Z
//���� : -9
// ���Ű������� : (ASCII��������UltraEdit�Ĳ˵�view->ASCII Table�鿴) !"#$%&'()*+,-./ (ASCII��:x21~0x2F)
//		  (ASCII <= > <= > <= > <= > <= >��:x3A~0x40) (ASCII�� : x5B~0x60)
//		  (ASCII�� : x7B~0x7E)
//		  Input Param
//		  String pPasswordStr : ���룬���ַ�����ʽ��š�
//		  Return Value
//		  ���ݹ��������İ�ȫ�ȼ���
//		  public static Safelevel GetPwdSecurityLevel(String pPasswordStr)
//{
//			  /*������ʵ�ֹ���*/
//			  return null;
//		  }
//	 :; <= > ? @
//		 [\] ^ _` { | }~
//	 �ӿ�����:
// �������� : ����һ��string������
// ������� : �������ȼ�
//	ʾ��1 :
//	 ���� 38$@NoNoNo
//		 ��� VERY_SECURE

#include<iostream>
#include<string>
using namespace std;

int numChar(string str, int k)
{
    //����ASCII���ж���ĸ��Сд 
    int small = 0;
    int big = 0;
        for (int i = 0; i < k; i++) {
            if (str[i] >= 65 && str[i] <= 90)   // ��д�ַ�
                big++;
            else if (str[i] >= 97 && str[i] <= 122) // Сд�ַ�
                small++;
    }

    if ((small + big) == 0)
        return 0;
    else if (small == k || big == k)
        return 10;
    else //if (small > 0 && big > 0)
        return 20;
    //return 0;
}

int numNumber(string str, int k)
{
    //����ASCII���ж����ָ�������ȥ�ַ���0��֮����0~9֮��ļ�Ϊ���� 
    int num = 0;
    for (int i = 0; i < k; i++)
    {
        if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
            num++;
    }

    if (num == 0)
        return 0;
    else if (num == 1)
        return 10;
    else
        return 20;
}

int numSymbal(string str, int k)
{
    int num = 0;
    for (int i = 0; i < k; i++)
    {
        //��ȥ��ĸ�����֣�������Ϊ����
        if (!(str[i] >= 65 && str[i] <= 90)
            && !(str[i] >= 97 && str[i] <= 122)
            && !(str[i] - '0' >= 0 && str[i] - '0' <= 9))
            num++;
    }

    if (num == 0)
        return 0;
    else if (num == 1)
        return 10;
    else
        return 25;
}

int main() {
    string str;
    while (cin >> str) {
        int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;

        int k = str.size(); // �õ��ַ����ĳ��ȷ���
        if (k <= 4)
            sum1 = 5;
        else if (k >= 8)
            sum1 = 25;
        else
            sum1 = 10;

        sum2 = numChar(str, k);     // �õ���ĸ����
        sum3 = numNumber(str, k);   // �õ����ַ���
        sum4 = numSymbal(str, k);   // �õ����ŷ���

        // ������
        if ((sum2 > 0) && (sum3 > 0) && (sum4 > 0))
        {
            if (sum2 == 10)
                sum5 = 3;
            else
                sum5 = 5;
        }
        else if (sum2 > 0 && sum3 > 0 && sum4 == 0)
            sum5 = 2;

        int sum = sum1 + sum2 + sum3 + sum4 + sum5; // �ܵ÷�
        if (sum >= 90)
            cout << "VERY_SECURE" << endl;
        else if (sum >= 80)
            cout << "SECURE" << endl;
        else if (sum >= 70)
            cout << "VERY_STRONG" << endl;
        else if (sum >= 60)
            cout << "STRONG" << endl;
        else if (sum >= 50)
            cout << "AVERAGE" << endl;
        else if (sum >= 25)
            cout << "WEAK" << endl;
        else
            cout << "VERY_WEAK" << endl;
    }
    return 0;
}