#include "binarySortTree.h"
#include <iostream>
using namespace std;

int main()
{
	dg::BinarySortTree<int> bst;

	bst.insert(5);
	bst.insert(3);
	bst.insert(8);
	bst.insert(6);
	bst.insert(4);
	bst.insert(7);
	bst.insert(1);
	bst.insert(2);

	bst.erase(2);
	vector<int> v = bst.InOrder();

	for (auto& i : v)
	{
		cout << i << ' ';
	}

	return 0;
}