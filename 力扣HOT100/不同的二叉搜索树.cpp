#include <bits/stdc++.h>

using namespace std;

/**
 * 不同的二叉搜索树
 */

class Solution {
   public:
    /**
     * 思路：假设n个节点存在二叉搜索树的个数是G(n)，令f(i)表示以i为根节点的二叉搜索树，则：
     * G(n) = f(1) + f(2) + ... + f(n)
     * 当以i为根节点时：f(i) = G(i-1) * G(n-i),左子树有i-1个结点，右子树有n-i个结点
     * 综上有：G(n) = G(0)*G*(n-1) + G(1)*G(n-2) + ... + G(n-1)*G(0) 卡特兰数 
     * 通过dp来实现
     */
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};