#include <stdio.h>
#include <stdlib.h>

typedef union {
	long i;
	char j[10];
	int k;
}DATE;

struct data {
	int m;
	DATE n;
	double l;
}test;


int main() {
	DATE max;
	printf("%d %d %d", sizeof(struct data), sizeof(max), sizeof(int *));
	return 0;
}