#include <iostream>
using namespace std;

//ɾ���ַ�����β�ո��м�������ո�ֻ��һ����ԭ���ַ�����˳�򲻱䡣

void Deblank(char * str) {
	int flag = 0;	//����û��ʼ����ո�
	int p = 0;
	int i = 0;
	while (str[i]) {
		//�����ո� ��û��ʼ����
		if (!flag && str[i] == ' ') {
			i++;
		}
		//�������ǿո� ��û��ʼ����
		else if (!flag && str[i] != ' ') {
			flag = 1;
			str[p++] = str[i++];
		}
		//�����ո� ��ʼ������
		else if (flag && str[i] == ' ') {
			flag = 0;
			str[p++] = str[i++];
		}
		//�������ǿո� ��ʼ������
		else //if(flag && str[i] != ' ')
		{
			flag = 1;
			str[p++] = str[i++];
		}
	}

	if (str[p - 1] == ' ') {
		str[p - 1] = '\0';
	}
	else
		str[p] = '\0';
}

int main() {
	char array[] = "  asadad   q    ";

	Deblank(array);
	cout << array << endl;

	return 0;
}