#pragma once
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

namespace dg {

// 节点的颜色
enum Color { RED, BLACK };

// 红黑树节点的定义
template <class T>
class RBTreeNode
{
	T m_data;
	RBTreeNode<T>* m_left;
	RBTreeNode<T>* m_right;
	RBTreeNode<T>* m_parent;
	Color m_color;
public:
	RBTreeNode(const T& val = T(), Color color = RED) :
		m_left(nullptr),
		m_right(nullptr),
		m_parent(nullptr),
		m_data(val),
		m_color(color)
	{}

	template <class T>
	friend class RBTree;
};

template <class T>
class RBTree
{
	RBTreeNode<T>* m_head;

	// 左旋
	void lRound(RBTreeNode<T>* pre)
	{
		RBTreeNode<T>* parent = pre->m_parent;
		RBTreeNode<T>* cur = pre->m_right;
		cur->m_parent = parent;
		if (parent != m_head)
		{
			if (parent->m_left == pre)
			{
				parent->m_left = cur;
			}
			else
			{
				parent->m_right = cur;
			}
		}
		else
		{
			m_head->m_parent = cur;
			cur->m_parent = m_head;
		}

		pre->m_right = cur->m_left;
		if (cur->m_left)
		{
			cur->m_left->m_parent = pre;
		}
		cur->m_left = pre;
		pre->m_parent = cur;
	}

	// 右旋
	void rRound(RBTreeNode<T>* pre)
	{
		RBTreeNode<T>* parent = pre->m_parent;
		RBTreeNode<T>* cur = pre->m_left;
		cur->m_parent = parent;
		if (parent != m_head)
		{
			if (parent->m_left == pre)
			{
				parent->m_left = cur;
			}
			else
			{
				parent->m_right = cur;
			}
		}
		else
		{
			m_head->m_parent = cur;
			cur->m_parent = m_head;
		}
		pre->m_left = cur->m_right;
		if (cur->m_right)
		{
			cur->m_right->m_parent = pre;
		}
		cur->m_right = pre;
		pre->m_parent = cur;
	}
public:
	RBTree()
	{
		m_head = new RBTreeNode <T>;
	}

	// 得到根节点（头节点父亲）
	RBTreeNode<T>*& getRoot()
	{
		return m_head->m_parent;
	}

	// 返回树的最左端节点
	RBTreeNode<T>* leftMost()
	{
		RBTreeNode<T>* cur = getRoot();
		for (; cur->m_left; cur = cur->m_left);
		return cur;
	}

	// 返回树的最右端节点
	RBTreeNode<T>* rightMost()
	{
		RBTreeNode<T>* cur = getRoot();
		for (; cur->m_right; cur = cur->m_right);
		return cur;
	}

	bool insert(const T& val)
	{
		RBTreeNode<T>*& root = getRoot();
		if (root)
		{
			// 插入节点
			RBTreeNode<T>* cur = root;
			RBTreeNode<T>* pre = nullptr;
			while (cur)
			{
				if (val < cur->m_data)
				{
					pre = cur;
					cur = cur->m_left;
				}
				else if (val > cur->m_data)
				{
					pre = cur;
					cur = cur->m_right;
				}
				else
				{
					return false;
				}
			}
			cur = new RBTreeNode<T>(val);
			if (val < pre->m_data)
			{
				pre->m_left = cur;
			}
			else
			{
				pre->m_right = cur;
			}
			cur->m_parent = pre;
			/*****************红黑树*****************/
			if (pre->m_color == RED)
			{
				RBTreeNode<T>* grand = pre->m_parent;
				RBTreeNode<T>* uncle;
				if (pre == grand->m_left)
				{
					while (pre != m_head && pre->m_color == RED)
					{
						grand = pre->m_parent;
						uncle = grand->m_right;
						if (uncle && uncle->m_color == RED) //第二种情况
						{
							pre->m_color = BLACK;
							uncle->m_color = BLACK;
							grand->m_color = RED;
							cur = grand;
							pre = cur->m_parent;
						}
						else
						{
							if (cur == pre->m_right) //第三种情况转成第一种
							{
								lRound(pre);
								RBTreeNode<T>* tmp;
								tmp = pre;
								pre = cur;
								cur = tmp;
							}
							rRound(grand);        //第一种情况
							pre->m_color = BLACK;
							grand->m_color = RED;
							break;
						}
					}
				}
				else /*************上下是镜像**************/
				{
					while (pre != m_head && pre->m_color == RED)
					{
						grand = pre->m_parent;
						uncle = grand->m_left;
						if (uncle && uncle->m_color == RED)
						{
							pre->m_color = BLACK;
							uncle->m_color = BLACK;
							grand->m_color = RED;
							cur = grand;
							pre = cur->m_parent;
						}
						else
						{
							if (cur == pre->m_left)
							{
								rRound(pre);
								RBTreeNode<T>* tmp;
								tmp = pre;
								pre = cur;
								cur = tmp;
							}
							lRound(grand);
							pre->m_color = BLACK;
							grand->m_color = RED;
							break;
						}
					}
				}
			}
			//省略的else是第四种情况（pre->m_color == BLACK）
		}
		// 插入根节点（根节点不存在）
		else 
		{
			root = new RBTreeNode<T>(val, BLACK);
			root->m_parent = m_head;
			m_head->m_parent = root;
		}
		root->m_color = BLACK;
		m_head->m_left = leftMost();
		m_head->m_right = rightMost();
		m_size++;

		return true;
	}

	std::vector<T> InOrder()
	{
		std::stack<RBTreeNode<T>*> s;
		std::vector<T> res;
		RBTreeNode<T>* cur = m_head->m_parent;

		while (cur || !s.empty())
		{
			for (; cur; cur = cur->m_left)
			{
				s.push(cur);
			}

			if (!s.empty())
			{
				cur = s.top();
				res.push_back(cur->m_data);
				s.pop();

				cur = cur->m_right;
			}
		}

		return res;
	}

	bool IsValidRBTree()
	{
		RBTreeNode<T>* pRoot = getRoot();
		
		// 空树也是红黑树
		if (nullptr == pRoot)
			return true;

		// 检测根节点是否满足情况
		if (BLACK != pRoot->m_color) {
			cout << "违反红黑树性质二:根节点必须为黑色" << endl;
			return false;
		}

		// 获取任意一条路径中黑色节点的个数 
		size_t blackCount = 0;
		RBTreeNode<T>* pCur = pRoot;
		while (pCur)
		{
			if (BLACK == pCur->m_color)
				blackCount++;
			pCur = pCur->m_left;
		}
		// 检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数 
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}
	bool _IsValidRBTree(RBTreeNode<T>* pRoot, size_t k, const size_t blackCount)
	{
		//走到null之后，判断k和black是否相等 
		if (nullptr == pRoot)
		{
			if (k != blackCount)
			{
				cout << "违反性质四:每条路径中黑色节点的个数必须相同" << endl;
				return false;
			}
			return true;
		}

		// 统计黑色节点的个数
		if (BLACK == pRoot->m_color)
			k++;

		// 检测当前节点与其双亲是否都为红色
		RBTreeNode<T>* pParent = pRoot->m_parent;
		if (pParent && RED == pParent->m_color && RED == pRoot->m_color) {
			cout << "违反性质三:没有连在一起的红色节点" << endl;
			return false;
		}
		return _IsValidRBTree(pRoot->m_left, k, blackCount) && 
			   _IsValidRBTree(pRoot->m_right, k, blackCount);
	}

	// 找迭代器的下一个节点，下一个节点肯定比其大
	RBTreeNode<T>* increasement(RBTreeNode<T>* cur)
	{
		RBTreeNode<T>* tmp = cur;
		if (cur->m_right)
		{
			// 右子树中最小的节点，即右子树中最左侧节点
			tmp = cur->m_right;
			for (; tmp->m_left; tmp = tmp->m_left);
		}
		else
		{
			// 右子树不存在，向上查找
			tmp = tmp->m_parent;
			for (; cur != tmp->m_left && tmp != m_head; tmp = tmp->m_parent)
			{
				cur = tmp;
			}
			// tmp 为根节点并且没右子树
			if (tmp == m_head)
			{
				return nullptr;
			}
		}
		return tmp;
	}

	// 获取迭代器指向节点的前一个节点
	RBTreeNode<T>* decreasement(RBTreeNode<T>* cur)
	{
		RBTreeNode<T>* tmp = cur;
		if (cur->m_left)
		{
			tmp = cur->m_left;
			for (; tmp->m_right; tmp = tmp->m_right);
		}
		else
		{
			tmp = tmp->m_parent;
			for (; cur != tmp->m_right && tmp != m_head; tmp = tmp->m_parent)
			{
				cur = tmp;
			}
			if (tmp == m_head)
			{
				return nullptr;
			}
		}
		return tmp;
	}

};

};