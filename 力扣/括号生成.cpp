#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/**
 * 题目22：括号生成
 */
class LeeCode22 {
   public:
    /**
     * 思路：回溯法，深度优先遍历。"做减法"
     * 利用树型结构做减法
     * (1) 当左右括号数都大于0时，可以产生分支；
     * (2) 当产生左分支时，只看当前是否还有左括号使用；
     * (3) 当产生右分支时，右括号的数量要大于左括号的数量；
     * (4) 当左括号和右括号数量都剩余0时，生成结束。
     */
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n <= 0) {
            return res;
        }
        string str = "";
        // DFS1(str, n, n, res);
        DFS2(str, 0, 0, n, res);
        return res;
    }

    /**
     * 思路：动态规划
     * 第一步：定义状态dp[i]:表示使用i对括号能够生成的所有符合条件的组合；
     * 第二步：状态转移方程；
     *      (1)考虑i对括号的所有组合是在i-1对括号组合的基础上得到的，考虑整个括号排列的最左边的括号，
     *      它一定是一个左括号，那么它可以和它对应的右括号组成一组完整的括号，并认为这一组是相比i-1新加进来的括号。
     *      (2)剩下的i-1组括号，要么在这一组新增的括号内部，要么在这一组新增的括号外部（右侧）。
     *      即dp[i] = '('+[i=p时所有括号的排列组合] + ')'
     * +[i=q时所有括号的排列组合] 其中p+q=1，当p 从 0 取到 i-1，q 从 i-1 取到 0
     * 后，所有情况就遍历完了.
     */
    vector<string> generateParenthesis02(int n) {
        vector<string> res;
        if (n <= 0) {
            return res;
        }
        // 定义动态数组，用于存储n对括号的所有排列组合
        vector<vector<string>> dp;
        vector<string> dp0;  // 初始状态
        dp0.push_back("");
        dp.push_back(dp0);
        // 遍历所有的括号对，相当于自底到上
        for (int i = 1; i <= n; i++) {
            vector<string> cur;  // 用于保存当前括号对数下的所有组合
            // 更新动态数组数组
            for (int j = 0; j < i; j++) {
                // 位于新增括号内部的括号排列组合
                vector<string> str1 = dp[j];
                // 位于新增括号外部的括号排列组合
                vector<string> str2 = dp[i - 1 - j];
                for (string s1 : str1) {
                    for (string s2 : str2) {
                        // 使用状态转移方程获取当前括号对数下的所有组合
                        cur.push_back('(' + s1 + ')' + s2);
                    }
                }
            }
            dp.push_back(cur);
        }
        return dp[n];
    }

   private:
    /**
     * DFS做减法
     */
    void DFS1(string curStr, int left, int right, vector<string>& res) {
        // 左括号和右括号剩余数都为0时生成结束
        if (left == 0 && right == 0) {
            res.push_back(curStr);
            return;
        }
        if (left > 0) {  // 生成左分支的条件
            // 注意回溯法的传参方法，保证了不破坏当前的curStr
            DFS1(curStr + '(', left - 1, right, res);
        }
        if (left < right && right > 0) {  // 生成右分支的条件
            // 注意回溯法的传参方法，保证了不破坏当前的curStr
            DFS1(curStr + ')', left, right - 1, res);
        }
    }

    /**
     * DFS 做加法，思路类似
     */
    void DFS2(string curStr, int left, int right, int n, vector<string>& res) {
        if (left == n && right == n) {
            res.push_back(curStr);
            return;
        }
        if (left < n) {
            DFS2(curStr + '(', left + 1, right, n, res);
        }
        if (left > right && right < n) {
            DFS2(curStr + ')', left, right + 1, n, res);
        }
    }
};