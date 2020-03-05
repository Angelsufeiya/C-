#include <iostream>
#include <cstdio>
using namespace std;

struct Poker{
	char type;
	char point;
};

enum{
	spades,	//黑桃
	hearts,	//红桃
	clubs,	//梅花
	diamonds,//方片
	joker,	//大小王
};

void input_poker(Poker * pk){
	char a, b;
	scanf("%c%d", &pk->type, &pk->point);
	pk->type -= 'a';

	if (pk->type == joker){
		pk->point += 13;
	}
	while (getchar() != '\n');
}

void output_poker(Poker k){
	char *type[5] = { "黑桃", "梅花", "梅花", "方片", " " };
	char *point[16] = { "", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "小王", "大王" };

	printf("%s%s\n", type[k.type], point[k.point]);
}

void InsertSort(Poker* src, int n, bool(*cmp)(Poker, Poker)) {
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


int main(){
	Poker p[5];
	
	int i;
	for (i = 0; i < 5; i++){
		input_poker(p + i);
	}

	return 0;
}