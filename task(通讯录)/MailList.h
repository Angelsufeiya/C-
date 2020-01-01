#ifndef _MailList_H
#define _MailList_H
//声明一般放在头文件里

#define PERSPACE 100
#define FILENAME "maillist.txt"

enum{
	ADD_MSG = 1,
	DELETE_MSG,
	SEARCH_MSG,
	CHANGE_MSG,
	DISPLAY_MSG,
	EMPTY_MSG,
	SAVE_FILE
};

//结构体 struct MailList 的声明
struct MailList{
	char name[50];	//名字
	char gender;	//性别
	char telnum[30];//电话
	char addr[200];	//住址
	int age;		//年龄
};

//声明结构体MailLists
typedef struct{
	struct MailList * allMsg;//声明结构体变量 allMsg
	int count;
	int limit;
}MailLists;

void inputData(struct MailList * oneData);
void initMailList(MailLists * data);
void destoryMailList(MailLists * data);
void addMailList(MailLists * data, struct MailList oneData);
void searchData(MailLists data, char * find, int * searchres);
void deleteOneData(MailLists * data, int n);
void outputData(MailLists data);
void outputSearchData(MailLists data, int * outputdata);
int catchOneData(MailLists data, char *find);

#endif /* _MailList_H */