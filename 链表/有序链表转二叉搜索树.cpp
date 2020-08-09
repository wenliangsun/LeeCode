#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nodes;
        while (head) {
            nodes.push_back(head->val);
            head = head->next;
        }
        return dfs(nodes, 0, nodes.size() - 1);
    }

    TreeNode* dfs(vector<int>& nodes, int l, int r) {
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        auto root = new TreeNode(nodes[mid]);
        root->left = dfs(nodes, l, mid - 1);
        root->right = dfs(nodes, mid + 1, r);
        return root;
    }
};