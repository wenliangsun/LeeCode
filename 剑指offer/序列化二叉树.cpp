#include <bits/stdc++.h>

using namespace std;

/**
 * 序列化二叉树
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
   public:
    string serialize(TreeNode* root) {
        string res;
        dfs1(root, res);
        return res;
    }

    /**
     * 先序遍历 结果存储成字符串
     */
    void dfs1(TreeNode* root, string& res) {
        if (!root) {
            res += "#,";
            return;
        }
        res += to_string(root->val) + ',';
        dfs1(root->left, res);
        dfs1(root->right, res);
    }

    TreeNode* deserialize(string data) {
        int idx = 0;
        return dfs2(data, idx);
    }
    /**
     * 根据先序遍历构建二叉树 先序遍历的结果是一个特殊的字符串
     */
    TreeNode* dfs2(string& data, int& idx) {
        if (data[idx] == '#') {
            idx += 2;  // 跳过#号
            return nullptr;
        }
        int t = 0;
        bool is_minus = false;
        if (data[idx] == '-') {
            is_minus = true;
            idx++;
        }
        while (data[idx] != ',') {
            t = t * 10 + data[idx] - '0';
            idx++;
        }
        idx++;  //跳过逗号
        if (is_minus) t = -t;
        auto root = new TreeNode(t);
        root->left = dfs2(data, idx);
        root->right = dfs2(data, idx);
        return root;
    }
};
