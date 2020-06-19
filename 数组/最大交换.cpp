#include <bits/stdc++.h>

using namespace std;

/**
 * 题目670：最大交换
 */

class Solution {
   public:
    /**
     * 思路：首先将数字转换成字符串，然后从后向前统计到当前位置的最大数字，最后从前向后遍历，
     * 如果当前数字小于从当前位置到最后的最大值，则交换这两个数字，跳出循环。
     */
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<int> mx(s.size());  // 用于记录从后到当前位置的最大数字
        mx[s.size() - 1] = s.size() - 1;
        // 从后向前计算从后到当前位置的最大数字
        for (int i = s.size() - 2; i >= 0; i--) {
            if (s[i] > s[mx[i + 1]])
                mx[i] = i;
            else
                mx[i] = mx[i + 1];
        }
        // 从前向后遍历，如果当前值的数字小于从当前位置向后的数字的最大值，则交换。
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] < s[mx[i]]) {
                swap(s[i], s[mx[i]]);
                break;
            }
        }
        return stoi(s);
    }
};