#include <iostream>
#include <string>
#include <vector>

#include "TreeNode.h"

using namespace std;

/**
 * 二叉树的序列化和反序列化
 */
class Solution {
   public:
    string serialize(TreeNode* root) {
        string res;
        DFSSerialize(root, res);
        return res;
    }

    TreeNode* deserialize(string data) {
        int idx = 0;
        return DFSDeserialize(data, idx);
    }

   private:
    void DFSSerialize(TreeNode* root, string& res) {
        if (!root) {
            res += "#,";
            return;
        }
        res += to_string(root->val) + ',';
        DFSSerialize(root->left, res);
        DFSSerialize(root->right, res);
    }

    TreeNode* DFSDeserialize(string& data, int& idx) {
        if (data[idx] == '#') {
            idx += 2;
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
        idx++;  // 跳过逗号
        if (is_minus) t = -t;
        auto root = new TreeNode(t);
        root->left = DFSDeserialize(data, idx);
        root->right = DFSDeserialize(data, idx);
        return root;
    }
};
