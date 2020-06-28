#include <bits/stdc++.h>

using namespace std;

/**
 * 题目401：二进制手表
 */

class Solution {
   public:
    vector<bool> st;
    vector<string> res;

    int m[10] = {1, 2, 4, 8, 1, 2, 4, 8, 16, 32};

    vector<string> readBinaryWatch1(int num) {
        pair<int, int> t(0, 0);
        dfs(num, t, 0);
        return res;
    }

    /**
     * 回溯法
     */
    void dfs(int num, pair<int, int> time, int idx) {
        if (num == 0) {
            if (time.first < 12 && time.second < 60) {
                res.push_back(to_string(time.first) + ":" +
                              (time.second < 10 ? "0" + to_string(time.second)
                                                : to_string(time.second)));
            }
            return;
        }
        for (int i = idx; i < 10; i++) {
            // 剪枝
            if (time.first > 11 || time.second > 59) continue;
            pair<int, int> tmp = time;
            if (i < 4)
                time.first += m[i];
            else
                time.second += m[i];
            dfs(num - 1, time, i + 1);
            time = tmp;
        }
    }

    /**
     * 换一种思考方式！！！
     * 直接遍历，然后统计出符合要求的即可  利用统计二进制表示中1的个数的代码模板
     */
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 60; j++)
                if (count1(i) + count1(j) == num)
                    res.push_back(to_string(i) + ":" +
                                  (j < 10 ? "0" + to_string(j) : to_string(j)));

        return res;
    }

    int count1(int num) {
        int res = 0;
        while (num) {
            res++;
            num = num & (num - 1);
        }
        return res;
    }
};
