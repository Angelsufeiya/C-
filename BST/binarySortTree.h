#pragma once

#include <vector>
#include <stack>

namespace dg {

template <class T>
class TreeNode
{
	T m_data;
	TreeNode<T>* m_left;
	TreeNode<T>* m_right;
public:
	TreeNode(const T& val = T()) :
		m_data(val),
		m_left(nullptr),
		m_right(nullptr)
	{}

	template <class T>
	friend class BinarySortTree;
};

template <class T>
class BinarySortTree
{
	TreeNode<T>* m_root;

	void destroy(TreeNode<T>* root)
	{
		if (root)
		{
			destroy(root->m_left);
			destroy(root->m_right);
			delete root;
		}
	}
public:
	BinarySortTree() :
		m_root(nullptr)
	{}

	bool insert(const T& val)
	{
		if (m_root == nullptr)
		{
			m_root = new TreeNode<T>(val);
			return true;
		}

		TreeNode<T>* cur = m_root;
		TreeNode<T>* pre = nullptr;

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

		cur = new TreeNode<T>(val);
		if (val < pre->m_data)
		{
			pre->m_left = cur;
		}
		else
		{
			pre->m_right = cur;
		}

		return true;
	}

	bool erase(const T& val)
	{
		if (m_root == nullptr)
		{
			return false;
		}

		TreeNode<T>* cur = m_root;
		TreeNode<T>* pre = m_root;

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
				break;
			}
		}

		if (cur == nullptr)
		{
			return false;
		}

		if (cur->m_left && cur->m_right)
		{
			TreeNode<T>* cur2 = cur->m_left;
			TreeNode<T>* pre2 = cur;

			if (cur2->m_right)
			{
				for (; cur2->m_right; pre2 = cur2, cur2 = cur2->m_right);
				pre2->m_right = cur2->m_left;	// ��������ӵ����������������׵���������
				cur2->m_left = cur->m_left;		// ���̳�Ҫɾ���ڵ���˼ʹ�ϵ����������
			}

			// cur2 ��ʱΪҪɾ���ĵ�������������ֵ
			cur2->m_right = cur->m_right;	// ���̳�Ҫɾ���ڵ���˼ʹ�ϵ����������

			if (cur == pre)
			{
				m_root = cur2;
			}
			else
			{
				if (cur->m_data < pre->m_data)
				{
					pre->m_left = cur2;		// ���̳�Ҫɾ���ڵ���˼ʹ�ϵ�����ף�
				}
				else
				{
					pre->m_right = cur2;	// ���̳�Ҫɾ���ڵ���˼ʹ�ϵ�����ף�
				}
			}

			delete cur;
		}
		else if (cur->m_left)
		{
			if (cur == pre)
			{
				m_root = cur->m_left;
			}
			else
			{
				if (cur->m_data < pre->m_data)
				{
					pre->m_left = cur->m_left;
				}
				else
				{
					pre->m_right = cur->m_left;
				}
			}
			delete cur;
		}
		else
		{
			if (cur == pre)
			{
				m_root = cur->m_right;
			}
			else
			{
				if (cur->m_data < pre->m_data)
				{
					pre->m_left = cur->m_right;
				}
				else
				{
					pre->m_right = cur->m_right;
				}
			}
			delete cur;
		}
	}

	/*
	���ǲ���������������
		�������������У�
			a��������û���Һ���
				ֱ�������Ӽ̳��Լ����Һ��Ӻ͸���
			b�����������Һ���
				һ·���ң��ҵ�����һ���Һ��ӣ�Ȼ��������ӵ�
				���������������׵��������ϣ�Ȼ�������̳�Ҫɾ����
				����˼ʹ�ϵ�����������͸��ף�
			��Ҫɾ���Ľڵ��Ǹ��ڵ�ʱ�����ü̳и��׹�ϵ����Ҫ�޸ĸ��ڵ�ָ��
		��ֻ��������
			ֱ�����������̳��Լ��ĸ��׹�ϵ�����Ҫɾ���Ǹ�����ô
			ֱ�ӻ������ɡ�
		������
			ֱ���������������߿գ��̳��Լ��ĸ��׹�ϵ������ͬ��
	*/

	//�������
	std::vector<T> InOrder()
	{
		std::stack<TreeNode<T>*> s;
		std::vector<T> res;
		TreeNode<T>* cur = m_root;

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
};

};