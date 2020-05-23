#include <string>
#include <vector>
using namespace std;

/**
 * 题目72：编辑距离
 */
class LeeCode72 {
   public:
    /**
     * 思路：递归法 自顶至下 存在重复计算，可采用备忘录方法
     * 从s1和s2的末尾，向前遍历，
     * 如果s1的当前字符和s2的当前字符相等，则什么都不做，向前遍历；
     * 如果s1的当前字符和s2的当前字符不相等，则有三种操作：取其中操作数最小的。
     *  1)在s1中插入字符
     *  2)在s1只删除字符
     *  3)在s1中修改字符
     * 如果s1走完，则需要在s1中插入s2的剩余字符
     * 如果s2走完，则需要在s1中删除剩余字符。
     *
     * 注意：对于当前子问题，从原问题得到的路径不止一条，一旦发现有重复路径，就存在大量的重复计算
     */
    int minDistance1(string word1, string word2) {
        return helper(word1, word1.size() - 1, word2, word2.size() - 1);
    }

    /**
     * 思路：动态规划 自底向上
     */
    int minDistance2(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1,
                               vector<int>(word2.size() + 1, 0));
        // base case
        for (int i = 0; i <= word1.size(); i++) {
            dp[i][0] = i;
        }
        // base case
        for (int j = 0; j <= word2.size(); j++) {
            dp[0][j] = j;
        }
        // 自底至上
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                // 如果两个字符相等，则不进行操作
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // 依次是插入、删除和替换
                    dp[i][j] = min(min(dp[i][j - 1] + 1, dp[i - 1][j] + 1),
                                   dp[i - 1][j - 1] + 1);
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }

   private:
    int helper(string word1, int i, string word2, int j) {
        // 边界情况
        if (i == -1) {
            return j + 1;
        }
        if (j == -1) {
            return i + 1;
        }
        // 如果有备忘录，则在此处判断是否已经计算过，若计算过，则直接返回
        // 如果相等，什么都不做！！！
        if (word1[i] == word2[j]) {
            return helper(word1, i - 1, word2, j - 1);
        } else {
            // 依次是插入、删除、替换
            return min(min(helper(word1, i, word2, j - 1) + 1,
                           helper(word1, i - 1, word2, j) + 1),
                       helper(word1, i - 1, word2, j - 1) + 1);
        }
    }
};