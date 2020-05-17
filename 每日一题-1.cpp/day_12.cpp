//����:�����Ʋ���
//	������32λ����n��m�����д�㷨��m�Ķ�������λ���뵽n�Ķ����Ƶĵ�j����iλ, ���ж����Ƶ�λ���ӵ�λ ������λ����0��ʼ��
//	����������int n��int m��ͬʱ����int j��int i�����������������뷵�ز������������֤n�ĵ�j����iλ��Ϊ �㣬��m�Ķ�����λ��С�ڵ���i - j + 1��
//�������� : 1024��19��2��6
//   ���� : 1100

class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        m <<= j;
        return n | m;
    }
};

//
//	���� : �������һ��ż����ӽ�����������
//		 ����һ��ż��(����2)��������2��������ɣ����ż����2�������кܶ������������ĿҪ��������ָ��
//		 ż��������������ֵ��С��������
//	 �������� :
//   ����һ��ż��
//   ������� : �����������
//	  ʾ��1 : ���� 20
//			���
//			7 13

#include <iostream>
#include <math.h>
using namespace std;

// �ж�����
bool IsPrime(int n) {
    // ֻ�����������������ܱ�������ߵ�����������һ�����ܱ������ұߵ�������
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