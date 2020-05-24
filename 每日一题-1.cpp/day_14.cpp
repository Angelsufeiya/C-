//����:�������ڵ�����ת��
//	������������ڣ���������һ��ĵڼ��졣��
//��ϸ���� : ����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��� ?
//   �ӿ���Ƽ�˵�� :
//		   /***************************************************************************** Description : ����ת��
//		   Input Param : year �������
//		   Month �����·� Day ������
//		   Output Param :
//		   Return Value : �ɹ�����0��ʧ�ܷ���-1(��:���ݴ���) *****************************************************************************/ public static int iConverDateToDay(int year, int month, int day)
//{
//			   /* ������ʵ�ֹ��ܣ��������������������*/
//			   return 0;
//		   }
//   /***************************************************************************** Description :
//   Input Param :
//   Output Param :
//   Return Value : �ɹ�:����outDay��������ĵڼ���;
//   ʧ��:����-1 *****************************************************************************/
//   public static int getOutDay() {
//	   return 0;
//   }
//��������:
//   �������У��ֱ����꣬�£���
//   ������� : �ɹ�������outDay��������ĵڼ���;
//   ʧ�ܣ����� - 1
//   ʾ��1: ���� 2012
//		12 31
//		���
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
//	���� : ���˵Ĵ���
//		 һ������������n����ÿ�������涼��һ������(ӵ����ͬ����������������)�����һ�����������˵ĵ� �ҽ���������ĺ���ĺʹ���������ĺ���Ļ���
//	 ���� : ��������������ĺ�����{ 1, 1, 2, 3 }��������Ӿ������˵ģ���Ϊ1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
//		  ������ʵ��Ӵ������Ƴ�һЩ��(�����Ƴ�0��, ���Ǳ��Ƴ���)��Ҫʹ�Ƴ���Ĵ��������˵ġ����������̼� ��һ������Ի�õĶ����ֲ�ͬ�����˵Ĵ��ӡ�
//	  �������� :
//   ��һ������һ��������n(n �� 1000)
//	   �ڶ���Ϊn����������xi(xi �� 1000) ������� : ������Բ��������˵Ĵ����� ʾ��1 :
//   ����
//	   3
//	   1 1 1
//	   ���
//	   2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
    getLuckyPacket:�ӵ�ǰλ�ÿ�ʼ��������Ҫ�����ϣ�һֱ���������һ��λ�ý��� 
    v: �����е�������
    n: �������
    pos: ��ǰ������λ��
    sum: ��Ŀǰλ�õ��ۼӺ�
    mul: ��Ŀǰλ�õ��ۻ�ֵ 
*/
int getLuckyPacket(vector<int> v, int n, int pos, int sum, int mul) {
    int count = 0; 
    //ѭ����������λ��i��ʼ���п��ܵ���� 
    for (int i = pos; i<n; i++)
    {
        sum += v[i];
        mul *= v[i];
        if (sum > mul)
        {
            //�ҵ�����Ҫ�����ϣ���1�������ۼӺ�����ֵ�����Ƿ��з���Ҫ��ļ���
            count += 1 + getLuckyPacket(v, n, i + 1, sum, mul);
        }
        else if (v[i] == 1)
        {
            //��β�����Ҫ���ҵ�ǰԪ��ֵΪ1��������������
            count += getLuckyPacket(v, n, i + 1, sum, mul);
        }
        else
        {
            //���sum����multi,������û�з���Ҫ��������
            break;
        }
        //Ҫ������һ��λ��֮ǰ�����Ȼָ�sum��multi
        sum -= v[i];
        mul /= v[i]; 
        //������ͬ����û��ʲô���𣬶�ֻ����һ����ϣ�����ֱ������ 
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