#include <bits/stdc++.h>

using namespace std;

/**
 * 题目1028：从先序遍历还原二叉树
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    /**
     * 使用迭代版本
     * 使用栈
     */
    TreeNode *recoverFromPreorder(string s) {
        int idx = 0;
        stack<TreeNode *> stk;
        while (idx < s.size()) {
            int level = 0;
            // 统计当前结点在第几层
            while (s[idx] == '-') idx++, level++;
            int t = 0;
            // 当前结点的数字
            while (idx < s.size() && s[idx] != '-') {
                t = t * 10 + s[idx] - '0';
                idx++;
            }
            // 构建当前结点
            auto root = new TreeNode(t);
            // 如果当前结点所在的层和栈的高度一样，则将栈顶元素的左子树指向当前结点
            if (level == stk.size()) {
                if (stk.size()) stk.top()->left = root;
                // 如果当前结点所在的层和栈的高度不一样，说明当前结点是右子结点，先将栈中的左子节点弹出，再将栈顶元素的右子树指向当前结点
            } else {
                while (level != stk.size()) stk.pop();
                stk.top()->right = root;
            }
            stk.push(root);
        }
        // 栈底元素是根节点
        while (stk.size() > 1) stk.pop();
        return stk.top();
    }
};