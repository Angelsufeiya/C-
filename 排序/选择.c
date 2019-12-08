#include <stdio.h>
#include <stdlib.h>

//打印函数
void printArr(int arr[], int sz){
	int i;
	for (i = 0; i < sz; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//选择排序函数
void selectSort(int a[], int n) 
{
	int min, tmp;
	int i, j;
	//每次循环数组，找出最小的元素，放在前面，前面的即为排序好的
	for (i = 0; i < n - 1; i++) 
	{
		min = i; //假设最小元素的下标
		for (j = i + 1; j < n; j++) {//将上面假设的最小元素与数组比较，交换出最小的元素的下标
			if (a[j] < a[min])
				min = j;
		}
		//若数组中真的有比假设的元素还小，就交换
		if (i != min)
		{
			tmp = a[i];
			a[i] = a[min];
			a[min] = tmp;
		}
	}
}

int main(){
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;

	printArr(arr, sz);
	selectSort(arr, sz);
	printArr(arr, sz);

	system("pause");
	return 0;
}