#include <stdio.h>

int main_s()
{
	char arr1[20] = { 0 };
	gets(arr1);		//²»ÄÜĞ´³É arr1 = gets()
	printf("arr = %s\n", arr1);

	return 0;
}