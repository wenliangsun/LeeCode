#include <bits/stdc++.h>

using namespace std;

/**
 * 判断一棵树是否是完全二叉树
 */

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution{
    public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool leaf = false; // 当前结点是否是叶子结点的一层
        while (q.size()) {
            auto t = q.front();
            q.pop();
            if (!t->left && t->right) return false; // 如果左孩子为null，右孩子不为null，则不是完全二叉树
            if (leaf && (t->left || t->right)) return false; // 如果当前结点是叶子结点，那么它应该没有左右孩子。 
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
            if (!t->left || !t->right) leaf = true; // 如果至少有一个是null，则说明使叶子结点。
        }
        return true;
    }
};