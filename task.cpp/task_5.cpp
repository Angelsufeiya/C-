#include <vector>
#include <stack>
#include <iostream>
#include <cstdio>
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) 
    {}
}TreeNode;

class Solution {
    vector<int> v;
    vector<int> tag;
    stack<TreeNode*> m_st;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* cur = root;

        while (cur || !m_st.empty()) {
            for (; cur; cur = cur->left) {
                m_st.push(cur);
                tag.push_back(0);
            }

            while (tag[tag.size() - 1] && !m_st.empty()) {
                cur = m_st.top();
                v.push_back(cur->val);
                m_st.pop();
            }

            if (!m_st.empty()) {
                cur = m_st.top();
                tag[tag.size() - 1] = 1;
                cur = cur->right;
            }
        }

        return v;
    }
    //返回根节点（二叉树的创建）
    TreeNode* BinaryTreeCreate(int* src) {
        static int s_n = 0;
        
        if (!src[s_n]) {
            return NULL;
        }
        if (src[s_n] == '#') {
            s_n++;
            return NULL;
        }

        TreeNode* cur = new TreeNode(src[s_n]);
        cur->val = src[s_n];
        s_n++;

        cur->left = BinaryTreeCreate(src);
        cur->right = BinaryTreeCreate(src);

        return cur;
    }
};

int main_60() {
    int arr[] = { 3, 1, 2};
    Solution p1;
    TreeNode* root = p1.BinaryTreeCreate(arr);
    vector<int> v = p1.postorderTraversal(root);
}