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
        if (root == nullptr) {
            return "";
        }
        DFSSerialize(root);
        string res = "[";
        for (auto s : temp) {
            if (res == "[") {
                res += s;
            } else {
                res += ',';
                res += s;
            }
        }
        res += ']';
        return res;
    }

    TreeNode* deserialize(string data) {
        if (data == "") {
            return nullptr;
        }
        vector<string> nums;
        string temp = "";
        int i = 1;
        while (i < data.size() - 1) {
            if (data[i] == ',' || i == data.size() - 1) {
                nums.push_back(temp);
                temp.clear();
                i++;
            }
            temp += data[i++];
        }
        vector<int> index(1, 0);
        TreeNode* root = DFSDeserialize(nums, index);
        return root;
    }

   private:
    vector<string> temp;
    void DFSSerialize(TreeNode* root) {
        if (root == nullptr) {
            temp.push_back("null");
            return;
        }
        temp.push_back(to_string(root->val));
        DFSSerialize(root->left);
        DFSSerialize(root->right);
    }

    TreeNode* DFSDeserialize(vector<string> data, vector<int> index) {
        if (index[0] == data.size()) {
            return nullptr;
        }
        if (data[index[0]] == "null") {
            index[0]++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(data[index[0]]));
        index[0]++;
        root->left = DFSDeserialize(data, index);
        root->right = DFSDeserialize(data, index);
        return root;
    }
};

int main() { Solution s = Solution(); }