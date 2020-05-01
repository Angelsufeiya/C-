#pragma once
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

namespace dg {

// �ڵ����ɫ
enum Color { RED, BLACK };

// ������ڵ�Ķ���
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

	// ����
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

	// ����
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

	// �õ����ڵ㣨ͷ�ڵ㸸�ף�
	RBTreeNode<T>*& getRoot()
	{
		return m_head->m_parent;
	}

	// ������������˽ڵ�
	RBTreeNode<T>* leftMost()
	{
		RBTreeNode<T>* cur = getRoot();
		for (; cur->m_left; cur = cur->m_left);
		return cur;
	}

	// �����������Ҷ˽ڵ�
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
			// ����ڵ�
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
			/*****************�����*****************/
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
						if (uncle && uncle->m_color == RED) //�ڶ������
						{
							pre->m_color = BLACK;
							uncle->m_color = BLACK;
							grand->m_color = RED;
							cur = grand;
							pre = cur->m_parent;
						}
						else
						{
							if (cur == pre->m_right) //���������ת�ɵ�һ��
							{
								lRound(pre);
								RBTreeNode<T>* tmp;
								tmp = pre;
								pre = cur;
								cur = tmp;
							}
							rRound(grand);        //��һ�����
							pre->m_color = BLACK;
							grand->m_color = RED;
							break;
						}
					}
				}
				else /*************�����Ǿ���**************/
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
			//ʡ�Ե�else�ǵ����������pre->m_color == BLACK��
		}
		// ������ڵ㣨���ڵ㲻���ڣ�
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
		
		// ����Ҳ�Ǻ����
		if (nullptr == pRoot)
			return true;

		// �����ڵ��Ƿ��������
		if (BLACK != pRoot->m_color) {
			cout << "Υ����������ʶ�:���ڵ����Ϊ��ɫ" << endl;
			return false;
		}

		// ��ȡ����һ��·���к�ɫ�ڵ�ĸ��� 
		size_t blackCount = 0;
		RBTreeNode<T>* pCur = pRoot;
		while (pCur)
		{
			if (BLACK == pCur->m_color)
				blackCount++;
			pCur = pCur->m_left;
		}
		// ����Ƿ��������������ʣ�k������¼·���к�ɫ�ڵ�ĸ��� 
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}
	bool _IsValidRBTree(RBTreeNode<T>* pRoot, size_t k, const size_t blackCount)
	{
		//�ߵ�null֮���ж�k��black�Ƿ���� 
		if (nullptr == pRoot)
		{
			if (k != blackCount)
			{
				cout << "Υ��������:ÿ��·���к�ɫ�ڵ�ĸ���������ͬ" << endl;
				return false;
			}
			return true;
		}

		// ͳ�ƺ�ɫ�ڵ�ĸ���
		if (BLACK == pRoot->m_color)
			k++;

		// ��⵱ǰ�ڵ�����˫���Ƿ�Ϊ��ɫ
		RBTreeNode<T>* pParent = pRoot->m_parent;
		if (pParent && RED == pParent->m_color && RED == pRoot->m_color) {
			cout << "Υ��������:û������һ��ĺ�ɫ�ڵ�" << endl;
			return false;
		}
		return _IsValidRBTree(pRoot->m_left, k, blackCount) && 
			   _IsValidRBTree(pRoot->m_right, k, blackCount);
	}

	// �ҵ���������һ���ڵ㣬��һ���ڵ�϶������
	RBTreeNode<T>* increasement(RBTreeNode<T>* cur)
	{
		RBTreeNode<T>* tmp = cur;
		if (cur->m_right)
		{
			// ����������С�Ľڵ㣬���������������ڵ�
			tmp = cur->m_right;
			for (; tmp->m_left; tmp = tmp->m_left);
		}
		else
		{
			// �����������ڣ����ϲ���
			tmp = tmp->m_parent;
			for (; cur != tmp->m_left && tmp != m_head; tmp = tmp->m_parent)
			{
				cur = tmp;
			}
			// tmp Ϊ���ڵ㲢��û������
			if (tmp == m_head)
			{
				return nullptr;
			}
		}
		return tmp;
	}

	// ��ȡ������ָ��ڵ��ǰһ���ڵ�
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