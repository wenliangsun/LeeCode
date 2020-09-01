#include <bits/stdc++.h>

using namespace std;

/**
 * 题目738：单调递增的数字
 */

class Solution {
   public:
    /**
     * 比如123454321，我们需要找到1234[54]321中的54这个位置，
     * 然后依次向左遍历，如果前一个比当前一个大，则需要对前一个减一
     */
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int idx = 1;
        while (idx < s.size() && s[idx - 1] <= s[idx]) idx++; // 找位置
        while (idx < s.size() && idx > 0 && s[idx - 1] > s[idx]) s[--idx]--; // 更新前面的数字使其为递增
        for (int i = idx + 1; i < s.size(); i++) s[i] = '9'; // 将之后的数字都置为9
        return stoi(s);
    }
};