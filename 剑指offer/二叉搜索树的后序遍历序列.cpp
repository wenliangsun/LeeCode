#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 利用后序遍历的性质和二叉搜索树的性质
     * 递归划分区间 并判断划分的区间是否符合上面的性质
     */
    bool verifyPostorder(vector<int>& postorder) {
        return dfs(postorder, 0, postorder.size() - 1);
    }

    bool dfs(vector<int>& postorder, int l, int r) {
        if (l >= r) return true;
        int p = l;
        // 寻找左区间
        while (postorder[p] < postorder[r]) p++;
        int m = p;
        // 判断右区间是否合法
        while (postorder[p] > postorder[r]) p++;
        // 左右区间合法 则判断左右区间是否是二叉搜索树的后序遍历
        return p == r && dfs(postorder, l, m - 1) && dfs(postorder, m, r - 1);
    }
};