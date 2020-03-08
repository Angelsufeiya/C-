#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
using namespace std;

struct Poker{
	char type;
	int point;
};

enum{
	spades,	//����
	hearts,	//����
	clubs,	//÷��
	diamonds,//��Ƭ
	joker,	//��С��
};

void input_poker(Poker * pk){
	//char a, b;
	scanf("%c%d", &pk->type, &pk->point);
	pk->type -= 'a';

	if (pk->type == joker){
		pk->point += 13;
	}
	while (getchar() != '\n');
}

void output_poker(Poker k){
	char *type[5] = { "����", "����", "÷��", "��Ƭ", "" };
	char *point[16] = { "", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "С��", "����" };

	printf("%s%s\n", type[k.type], point[k.point]);
}

//�ȶԱ������Ƶ�����С���ٶԱȻ�ɫ
bool cmppoker(Poker a, Poker b) {
	return (a.point < b.point) || (a.point == b.point && a.type < b.type);
}

//������ʽ����
bool cmplulaoye(Poker a, Poker b)
{
	if (a.point <= 2)
	{
		a.point += 11;
	}
	else if (a.point <= 13)
	{
		a.point -= 2;
	}

	if (b.point <= 2)
	{
		b.point += 11;
	}
	else if (b.point <= 13)
	{
		b.point -= 2;
	}
	return (a.point > b.point) || (a.point == b.point && a.type < b.type);
}

void InsertSort(Poker* src, int n, bool(*cmp)(Poker, Poker) = cmplulaoye) {
	int i, j;
	Poker tmp;

	for (i = 1; i < n; i++) {
		tmp = src[i];
		for (j = i; j > 0 && cmp(tmp, src[j - 1]); j--) {
			src[j] = src[j - 1];
		}
		src[j] = tmp;
	}
}

int main_20(){
	Poker p[5];
	
	int i;
	for (i = 0; i < 5; i++){
		input_poker(p + i);
	}

	InsertSort(p, 5);

	for (auto i : p) {
		output_poker(i);
	}

	return 0;
}