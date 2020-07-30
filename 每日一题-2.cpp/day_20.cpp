#include <stdio.h>
#include <stdlib.h>

int change(int *px){
	int y = 8;
	//y = y - *px;
	px = &y;
	return 0;
}

int main(){
	int xx = 3;
	int *pY = &xx;
	change(pY);
	printf("%d", *pY);
	system("pause");
	return 0;
}
