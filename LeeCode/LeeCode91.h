#include <string>

using namespace std;

/**
 * 题目91：解码方法
 */
class LeeCode91 {
   public:
    /**
     * 思路：动态规划
     * 思考这个整理动态方程的思路！！！
     * 状态转移方程：假设之前的字符串是abcx 新加进去的字符是y，则有五种情况
     * 1) x==0&&y==0, 不能编码，直接返回0；
     * 2) x==0&&y!=0, y只能单独放，此时dp[i] = dp[i-1];
     * 3) x!=0&&y==0, y不能单独放，只能和x合并，如果合并>26，则返回0，否则dp[i]
     * = dp[i-2]; 4) xy<26, y可单独放也可和x合并，此时dp[i] = dp[i-1] + dp[i-2];
     * 5) xy>26, y只能单独放，此时 dp[i] = dp[i-1]
     */
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        int dp[s.size() + 1];
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for (int i = 2; i <= s.size(); i++) {
            int num = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            // 第一种情况
            if (s[i - 1] == '0' && s[i - 2] == '0') {
                return 0;
                // 第二种情况
            } else if (s[i - 2] == '0') {
                dp[i] = dp[i - 1];
                //第三种情况
            } else if (s[i - 1] == '0') {
                if (num > 26) {
                    return 0;
                }
                dp[i] = dp[i - 2];
                // 第四种情况
            } else if (num <= 26) {
                dp[i] = dp[i - 1] + dp[i - 2];
                // 第五种情况
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[s.size()];
    }
};