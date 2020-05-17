#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//#define N 9 
//
//int x[N];
//int count = 0;
//
//void dump() {
//	int i = 0;
//	for (i = 0; i < N; i++) {
//		printf("%d", x[i]);
//	}
//	printf("\n");
//}
////½»»»º¯Êý
//void swap(int a, int b) {
//	int t = x[a];
//	x[a] = x[b];
//	x[b] = t;
//}
//
//void run(int n) {
//	int i;
//	if (N - 1 == n) {
//		dump();
//		count++; return;
//	}
//	for (i = n; i < N; i++) {
//		swap(n, i); 
//		run(n + 1); 
//		swap( n, i);
//	}
//}
//int main() {
//	int i;
//	for (i = 0; i < N; i++) {
//		x[i] = i + 1;
//	}
//	run(0);
//	printf("* Total: %d\n", count);
//}

//int main(){
//	int i = 3;
//	printf("%d %d", ++i, ++i);
//	return 0;
//}

//int main_0(){
//	char name[20] = "Mary";
//	FILE *out;
//	out = fopen("output.txt", "w");
//	if (out != NULL){
//		fprintf(out, "Hello %s\n", name);
//	}
//	return 0;
//}

int FindSubString(char* pch)
{
    int   count = 0;
    char* p1 = pch;
    while (*p1 != '\0')
    {
        if (*p1 == p1[1] - 1)
        {
            p1++;
            count++;
        }
        else {
            break;
        }
    }
    int count2 = count;
    while (*p1 != '\0')
    {
        if (*p1 == p1[1] + 1)
        {
            p1++;
            count2--;
        }
        else {
            break;
        }
    }
    if (count2 == 0)
        return(count);
    return(0);
}
void ModifyString(char* pText)
{
    char* p1 = pText;
    char* p2 = p1;
    while (*p1 != '\0')
    {
        int count = FindSubString(p1);
        if (count > 0)
        {
            *p2++ = *p1;
            sprintf(p2, "%i", count);
            while (*p2 != '\0')
            {
                p2++;
            }
            p1 += count + count + 1;
        }
        else {
            *p2++ = *p1++;
        }
    }
}

int main()
{
    char text[32] = "XYBCDCBABABA";
    ModifyString(text);
    printf(text);

    return 0;
}