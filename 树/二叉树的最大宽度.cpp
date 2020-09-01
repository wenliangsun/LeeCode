#include <bits/stdc++.h>

using namespace std;

/**
 * 题目662：二叉树的最大深度
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution {
public:
    typedef  unsigned long long LL;
    typedef pair<TreeNode*, LL> PII;
    /**
     * 由完全二叉树或二叉堆得到启发，即假设该树是完全二叉树（对空结点也进行标号），
     * 那么有：假设父节点的序号是i，那么左孩子的序号为2i，右孩子的序号为2i+1。对树进行广度优先搜索，
     * 采用pair存储结点信息与下标。用一个二维数组维护每一层的最左结点的序号，和最右结点的序号，
     * 最后对比每一层最左边和最右边结点的序号差即可.
     */
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<PII> q;
        vector<vector<LL>> res;
        q.push({root, 1});
        while (q.size()) {
            int len = q.size();
            vector<LL> tmp;
            for (int i = 0; i < len; i++) {
                auto node = q.front();
                q.pop();
                if (i == 0) tmp.push_back(node.second);
                if (i == len - 1) tmp.push_back(node.second);
                if (node.first->left) q.push({node.first->left, node.second * 2});
                if (node.first->right) q.push({node.first->right, node.second * 2 + 1});
            }
            res.push_back(tmp);
        }
        LL ans = 0;
        for (auto t : res) {
            ans = max(ans, t.back() - t.front() + 1);
        }
        return ans;
    }
};