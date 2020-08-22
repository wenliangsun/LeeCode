#include <stack>
#include <string>

using namespace std;

/**
 * 题目32：最长有效括号
 */
class LeeCode32 {
   public:
    /**
     * 思路：暴力法，列举所有可能的子串，然后判断是否是符号对
     * 时间复杂度太高：O(n^3)
     * 空间复杂度：O(n)
     */
    int longestValidParentheses1(string s) {
        if (s.empty()) {
            return 0;
        }
        int maxLen = 0;
        for (int i = 0; i < s.size(); i++) {
            // 注意这儿j的更新，下次加进来一对括号才有可能匹配成功
            for (int j = i + 2; j <= s.size(); j += 2) {
                if (isValidParenthess(s.substr(i, j - i))) {
                    maxLen = max(maxLen, j - i);
                }
            }
        }
        return maxLen;
    }

    /**
     * 思路：动态规划
     * 定义一个动态数组
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    int longestValidParentheses2(string s) {
        if (s.empty()) {
            return 0;
        }
        int maxLen = 0;    // 最大长度
        int dp[s.size()];  // 动态数组
        dp[0] = 0;         // 动态数组初始化
        // 遍历
        for (int i = 1; i < s.size(); i++) {
            // 如果当前字符是')'则有两种情况可以匹配成功
            if (s[i] == ')') {
                // 1.当前一个字符是'('时，它与当前字符配对，则dp[i] = dp[i-2]+2;
                if (s[i - 1] == '(') {
                    // 注意判断边界
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                    // 2.当前一个字符是')'时，就去找dp[i-1]匹配字符串的前面(即s[i-dp[i-1]-1]位置)
                    // 是否有'(',若有，则与当前的')'配对，此时配对字符串的长度由两部分组成
                    // 在dp[i-1]的基础上得到dp[i-1]+2，再考虑左侧匹配的'('之前的配对字符串长度,即dp[i-dp[i-1]-2]
                    // 所以dp[i] = dp[i-1]+2 + dp[i-dp[i-1]-2]
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + 2 +
                            ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0);
                } else {
                    dp[i] = 0;
                }

            } else {
                dp[i] = 0;
            }
            // 更新最大长度
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }

    /**
     * 思路：利用栈
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    int longestValidParentheses3(string s) {
        if (s.empty()) {
            return 0;
        }
        int maxLen = 0;
        stack<int> stk;
        // 存-1表示左边界，即指向配对括号子串的前一个字符
        stk.push(-1);
        for (int i = 0; i < s.size(); i++) {
            // 如果是左括号就入栈
            if (s[i] == '(') {
                stk.push(i);
                // 否则出栈，如果出栈后栈不为空则计算更新子串长度，若为空则将该位置入栈(即多余右括号的位置)
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    maxLen = max(maxLen, i - stk.top());
                }
            }
        }
        return maxLen;
    }

    /**
     * 思路：不需要额外的空间
     * 整个括号串中，要么只多余左括号，要么只多余右括号，多余的右括号必定在多余的左括号左侧！
     * (1)从左向右遍历时，相当于按多余的右括号划分区间，然后统计区间内匹配的子串的长度.如果区间内
     * 有多余的左括号，则该子串不匹配，并且这一子串一定在整个串的最右侧，多余的左括号一定在子串的最左侧。
     * (2)从右向左遍历时，相当于按照多余的左括号划分区间，然后统计区间内匹配子串的长度，如果区间内
     * 有多余的右括号，则该子串不匹配，并且这个子串一定在整个串的最左侧，多余的右括号一定在子串的最右侧。
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    int longestValidParentheses4(string s) {
        if (s.empty()) {
            return 0;
        }
        int leftnum = 0;
        int rightnum = 0;
        int maxLen = 0;
        // 从左向右遍历，统计左括号和右括号的数量
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                leftnum++;
            } else {
                rightnum++;
            }
            // 如果相等就更新最大长度
            if (leftnum == rightnum) {
                maxLen = max(maxLen, leftnum + rightnum);
                // 如果右括号大于左括号，则重置
            } else if (rightnum >= leftnum) {
                rightnum = 0;
                leftnum = 0;
            }
        }
        leftnum = 0;
        rightnum = 0;
        // 从右往左遍历，统计左括号和右括号的数量
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                leftnum++;
            } else {
                rightnum++;
            }
            if (leftnum == rightnum) {
                maxLen = max(maxLen, leftnum + rightnum);
                // 如果左括号大于右括号，则重置
            } else if (leftnum >= rightnum) {
                leftnum = 0;
                rightnum = 0;
            }
        }
        return maxLen;
    }

   private:
    // 判断字符串是否是符号对
    bool isValidParenthess(string s) {
        stack<char> stk;
        for (char c : s) {
            if (c == '(') {
                stk.push(c);
            } else if (!stk.empty() && stk.top() == '(') {
                stk.pop();
            } else {
                return false;
            }
        }
        return stk.empty();
    }
};