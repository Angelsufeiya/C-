#include "AVLTree.h"
#include <iostream>
using namespace std;

int main()
{
	dg::AVLTree<int> bst;

	bst.insert(5);
	bst.insert(2);
	bst.insert(8);
	bst.insert(0);
	bst.insert(4);
	bst.insert(7);
	bst.insert(9);
	bst.insert(1);
	bst.insert(3);
	bst.insert(6);
	
	//bst.insert(16);
	//bst.insert(3);
	//bst.insert(7);
	//bst.insert(11);
	//bst.insert(9);
	//bst.insert(26);
	//bst.insert(18);
	//bst.insert(14);
	//bst.insert(15);

	//bst.insert(4);
	//bst.insert(2);
	//bst.insert(6);
	//bst.insert(1);
	//bst.insert(3);
	//bst.insert(5);
	//bst.insert(15);
	//bst.insert(7);
	//bst.insert(16);
	//bst.insert(14);

	//bst.insert(1);
	//bst.insert(2);
	//bst.insert(3);
	//bst.insert(4);
	//bst.insert(5);
	//bst.insert(6);
	//bst.insert(7);
	//bst.insert(7);
	//bst.insert(6);
	//bst.insert(5);
	//bst.insert(4);
	//bst.insert(3);
	//bst.insert(2);
	//bst.insert(1);
	
	if (bst._IsBalanceTree(bst.m_root)) {
		cout << "是平衡二叉树：";
	}
	else {
		cout << "不是平衡二叉树：";
	}

	vector<int> v = bst.InOrder();

	for (auto& i : v)
	{
		cout << i << ' ';
	}
	return 0;
}