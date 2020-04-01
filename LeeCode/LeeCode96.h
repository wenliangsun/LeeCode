#include <unordered_map>

using namespace std;

/**
 * 题目96：不同的二叉搜索树
 */
class LeeCode96 {
   public:
    /**
     * 思路：递归法
     * n构成的二叉搜索树的树种F(n)等于1~n各个数分别作为跟的树种S(i)之和，
     * 即F(n) = S(1)+S(2)+...+S(n)
     * 而某个数作为根节点的树种等于其左子树种乘以右子树种，
     * 即S(i) = F(i的左子树)*F(i的右子树)
     */
    int numTrees(int n) {
        if (n == 0) {
            return 0;
        }
        return helper(1, n);
    }

    /**
     * 动态规划
     */
    int numTrees2(int n) {
        // 表示i个数构成的二叉搜索树种数，也可理解为[1,i]区间构成的树种数
        int dp[n + 1];
        for (int i = 0; i <= n; i++) {
            dp[i] = 0;
        }
        dp[0] = 1;
        dp[1] = 1;
        // 遍历每个数，可以理解为将区间向右扩展
        for (int end = 2; end <= n; end++) {
            // 当前区间中的每一个数作为根节点
            for (int mid = 1; mid <= end; mid++) {
                // 计算当前区间的树种数，右侧区间为[mid+1,end],区间长度为
                // end-mid-1+1 = end-mid
                dp[end] += dp[mid - 1] * dp[end - mid];
            }
        }
        return dp[n];
    }

   private:
    unordered_map<int, int> m;  // 记录区间长度的树种数
    /**
     * 暴力递归，有重复计算，不能AC ,自顶向下
     * 为什么会重复呢？
     * 不考虑数值，相同长度的区间构成的二叉搜索树的树种是一样的，如1~3和4~6区间长度都是3
     * 但是构成的树种数都是5，这就是重复的地方！！！
     */
    int helper(int begin, int end) {
        if (begin > end) {
            return 1;
        }
        int sum = 0;
        // 遍历当前区间，每一个数都当作根节点
        for (int i = begin; i <= end; i++) {
            // 计算左子树种和右子树种，并获得以当前根节点的树种数
            sum += helper(begin, i - 1) * helper(i + 1, end);
        }
        return sum;
    }
    /**
     * 递归，记录中间结果，减少重复计算
     * 即对不同区间长度的树种值进行记录来避免重复计算
     */
    int helper2(int begin, int end) {
        if (begin > end) {
            return 1;
        }
        int sum = 0;
        for (int i = begin; i <= end; i++) {
            int left =
                m[i - begin - 1] ? m[i - begin - 1] : helper2(begin, i - 1);
            int right = m[end - i - 1] ? m[end - i - 1] : helper2(i + 1, end);
            sum += left * right;
        }
        m[end - begin] = sum;
        return sum;
    }
};