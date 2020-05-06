#if 0
#include <iostream>
#include "hashMap.h"
using namespace std;

int main()
{
	HashSet<int> hs;

	hs.insert(5);
	hs.insert(8);
	hs.insert(13);
	hs.insert(7);
	hs.insert(2);
 	hs.insert(15);
	hs.insert(18);
	hs.insert(23);
	hs.insert(17);
	hs.insert(12);
	hs.insert(25);
	hs.insert(58);
	hs.insert(33);
	hs.insert(27);
	hs.insert(22);

	hs.erase(2);
	hs.erase(27);

	hs.clear();
	return 0;
}
#endif

#if 1
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

bool judgePrime(long long n)
{
	int sn = (int)sqrt(n);
	int i;
	for (i = 2; i <= sn; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	unsigned long long start = 26;

	unsigned long long i, j;
	int count = 0;
	for (i = start; i < 3E9; i *= 2)
	{
		for (j = i; !judgePrime(j); j++);
		count++;
		if (count % 5 == 0)
		{
			cout << endl;
		}
		printf("%10lld, ", j);
	}

	for (i = 0xffffffff; !judgePrime(i); i--);
	cout << i;
	return 0;
}
#endif