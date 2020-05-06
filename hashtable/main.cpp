#include <iostream>
#include "hashTable.h"
using namespace std;

int main_1()
{
	dg::hashTable<int, int> ht;

	ht.insert(pair<int, int>(1, 5));
	ht.insert(pair<int, int>(2, 7));
	ht.insert(pair<int, int>(5, 6));
	ht.insert(pair<int, int>(6, 8));
	ht.insert(pair<int, int>(12, 9));
	ht.insert(pair<int, int>(16, 4));
	ht.insert(pair<int, int>(23, 11));
	ht.insert(pair<int, int>(27, 13));

	ht.insert(pair<int, int>(33, 13));
	ht.insert(pair<int, int>(36, 13));
	return 0;
}

int main_2()
{
	dg::hashTable<string, int, dg::dealString> ht;

	ht.insert(pair<string, int>("abc", 1));
	ht.insert(pair<string, int>("def", 2));
	ht.insert(pair<string, int>("ghi", 3));
	ht.insert(pair<string, int>("jkl", 4));


	return 0;
}