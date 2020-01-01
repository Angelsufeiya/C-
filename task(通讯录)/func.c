#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "MailList.h"

void outputData(){
	int i;
	if (g_count == 0){
		printf("没有数据\n");
		return;
	}

	printf("  姓名    性别 年龄    电话      住址\n");
	for (i = 0; i < g_count; i++){
		printf("%-10s %3c %3d  %11s  %s\n", 
										g_AllMsg[i].name, 
										g_AllMsg[i].gender, 
										g_AllMsg[i].age, 
										g_AllMsg[i].telnum, 
										g_AllMsg[i].addr);

	}
}

void outputSearchdata(int * data){
	int i;
	if (data[0] == 0){
		printf("没有搜索到数据\n");
		return;
	}

	printf("     姓名    性别 年龄    电话      住址\n");
	for (i = 1; i < data[0]; i++){
		printf("%2d %-10s %3c %3d  %11s  %s\n", 
			i,
			g_AllMsg[data[i]].name,
			g_AllMsg[data[i]].gender,
			g_AllMsg[data[i]].age,
			g_AllMsg[data[i]].telnum,
			g_AllMsg[data[i]].addr);
	}
}

void catchOneData(char * find){
	int searchRes[1001] = { 0 };
	searchData(find, searchRes);
	if (searchRes[0] == 0){
		return -1;//删除信息错误
	}
	else if (searchRes[0] == 1){
		return searchRes[1];
	}
	else{
		int i;
		outputSearchdata(searchRes);
		printf("请输入你要删除第几条数据:\n");
		scanf("%d", &i);
		if (i < 1 || i > searchRes[0]){
			return -1;//删除信息错误
		}
		return searchRes[i];
	}
	return 0;
}

void deleteOneData(int n){
	int i;
	for (i = n; i < g_count; i++){
		g_AllMsg[i] = g_AllMsg[i + 1];
	}
	g_count--;//没有删除最后一条数据
}