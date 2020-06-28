#include <bits/stdc++.h>

using namespace std;

/**
 * 题目306：累加数
 */

class Solution {
   public:
    /**
     * 回溯法 + 大数问题
     */
    bool isAdditiveNumber(string num) { return dfs(num, 0, "", "", 0); }

    /**
     * idx: 字符串中的位置
     * pre：前一个数字
     * sum: 前面两个数字的和
     * k：第k个数字
     */
    bool dfs(string& num, int idx, string sum, string pre, int k) {
        // 如果到字符串末尾，则判断k是否符合条件，即k>2
        if (idx == num.size()) return k > 2;
        // 从当前位置向后遍历，寻找与前两个数字和相等的数字
        for (int i = idx; i < num.size(); i++) {
            string cur = num.substr(idx, i - idx + 1);  // 获取当前数字
            if (idx < i && cur[0] == '0') continue;  // 判断数字是否合法
            // 当前数字与前两个数字和不相等，则剪枝
            if (k >= 2 && cur != sum) continue;
            if (dfs(num, i + 1, add(pre, cur), cur, k + 1)) return true;
        }
        return false;
    }

    /**
     * 大数相加
     */
    string add(string s1, string s2) {
        int carry = 0;
        string res;
        for (int i = s1.size() - 1, j = s2.size() - 1;
             i >= 0 || j >= 0 || carry; i--, j--) {
            int n1 = i < 0 ? 0 : s1[i] - '0';
            int n2 = j < 0 ? 0 : s2[j] - '0';
            int sum = (n1 + n2 + carry) % 10;
            res += to_string(sum);
            carry = (n1 + n2 + carry) / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};