#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return (A && B) && (helper(A, B) || isSubStructure(A->left, B) ||
                            isSubStructure(A->right, B));
    }

    bool helper(TreeNode* p1, TreeNode* p2) {
        if (p2 == nullptr) return true;
        if (p1 == nullptr) return false;
        if (p1->val != p2->val) return false;
        return helper(p1->left, p2->left) && helper(p1->right, p2->right);
    }
};