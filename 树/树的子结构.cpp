#include <bits/stdc++.h>

using namespace std;

/**
 * 树的子结构
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    /**
     * 递归的思路  和树相关的问题，大都用递归
     */
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return (A && B) && (helper(A, B) || isSubStructure(A->left, B) ||
                            isSubStructure(A->right, B));
    }

    bool helper(TreeNode* p1, TreeNode* p2) {
        if (p2 == nullptr) return true;
        if (p1 == nullptr || p1->val != p2->val) return false;
        return helper(p1->left, p2->left) && helper(p1->right, p2->right);
    }
};