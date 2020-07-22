#include <bits/stdc++.h>

using namespace std;

/**
 * 二叉树的序列化与反序列化
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        dfs1(root, res);
        return res;
    }

    void dfs1(TreeNode* root, string& res) {
        if (!root) {
            res += "#,";
            return;
        }
        res += to_string(root->val) + ',';
        dfs1(root->left, res);
        dfs1(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return dfs2(data, idx);
    }

    TreeNode* dfs2(string& data, int& idx) {
        if (data[idx] == '#') {
            idx += 2;
            return nullptr;
        }
        bool is_minus = false;
        if (data[idx] == '-') {
            is_minus = true;
            idx++;
        }
        int t = 0;
        while (data[idx] != ',') {
            t = t * 10 + data[idx] - '0';
            idx++;
        }
        idx++;
        if (is_minus) t = -t;
        auto root = new TreeNode(t);
        root->left = dfs2(data, idx);
        root->right = dfs2(data, idx);
        return root;
    }
};