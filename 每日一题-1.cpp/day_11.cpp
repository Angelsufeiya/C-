//����:�����������
//��һ���������������������㰴�����һ��һ��ش����������α�ţ��������Ϊ1��������������� a��b��
//�����һ���㷨�����a��b�������������ȵı�š�
//��������int a, b��Ϊ�������ı�š��뷵��a��b������������ȵı�š�ע�������㱾��Ҳ����Ϊ������ �ȡ�
//�������� : 2��3
//   ���� : 1
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
//	���� : ���������bit��
//	 ���� : ��һ��byte���ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1
//	  ���� : һ��byte�͵�����
//	   ��� : ��
//		���� : ��Ӧ�Ķ�����������1�����������
//		 �������� : ����һ��byte����
//			������� : ���ת�ɶ�����֮������1�ĸ���

#include <iostream>
using namespace std;

int main() {
    int num;
    while (cin >> num) {
        int sum = 1, count = 0;

        while (num) {
            //��ȡ��ǰλ�Ķ�����ֵ 
            if (num & 1)
            {
                //���1��ֵ�����������ۼӣ����Ҹ��������� 
                ++count;
                if (count > sum) {
                    sum = count;
                }
            }
            else{
                count = 0;
            }
            //����һ�Σ�Ϊ��ȡ��һλ������ֵ��׼��
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
        i.resize(col, '��');
    }
    
    //��������

    return 0;
}