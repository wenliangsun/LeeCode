#include <bits/stdc++.h>

#include "ListNode.h"
#include "TreeNode.h"

using namespace std;

/**
 * 题目109：有序链表转二叉搜索树
 */

class Solution {
   public:
    /**
     * 将有序链表转换成有序数组，然后用有序数组转二叉搜索树来做  可以用快慢指针来寻找排序链表的中点
     * 时间复杂度：O(nlogn)
     * 空间复杂度：O(n)
     */
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> tmp;
        while (head) {
            tmp.push_back(head->val);
            head = head->next;
        }
        return dfs(tmp, 0, tmp.size() - 1);
    }

    TreeNode* dfs(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + right >> 1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = dfs(nums, left, mid - 1);
        root->right = dfs(nums, mid + 1, right);
        return root;
    }
};