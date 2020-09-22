#include <bits/stdc++.h>

using namespace std;

/**
 * 题目752：打开转盘锁
 */

class Solution {
   public:
    /**
     * 广度优先搜索
     */
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> hash;
        for (auto d : deadends) hash.insert(d);
        if (hash.count("0000")) return -1; // 排除0000也在deadends中
        queue<string> q;
        q.push("0000");
        int res = 0;
        int d[2] = {-1, 1};
        while (q.size()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                auto t = q.front();
                q.pop();
                if (t == target) return res;
                for (int j = 0; j < 4; j++) {
                    for (int k = 0; k < 2; k++) {
                        auto c = (t[j] - '0' + d[k] + 10) % 10 + '0';
                        auto tt = t;
                        tt[j] = c;
                        if (!hash.count(tt)) {
                            q.push(tt);
                            hash.insert(tt);
                        }
                    }
                }
            }
            res++;
        }
        return -1;
    }
};