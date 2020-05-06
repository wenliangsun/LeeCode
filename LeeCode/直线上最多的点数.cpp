#include <bits/stdc++.h>

using namespace std;

/**
 * 题目149：直线上最多的点数
 * 给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。
 */

class Solution {
   public:
    /**
     * 思路： 固定一点, 找其他点和这个点组成直线, 统计他们的斜率
     * 斜率采用最简式，用gcd算最大公约数
     */
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 0) return 0;
        if (n == 1) return 1;
        int res = 0;
        // 固定每一个点
        for (int i = 0; i < n - 1; i++) {
            unordered_map<string, int> hash;
            int repeat = 0, tmp = 0;
            // 计算之后的点与固定点的斜率 (因为之前的点和固定点的斜率已经算过了)
            for (int j = i + 1; j < n; j++) {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                if (dx == 0 && dy == 0) {  // 统计重复点
                    repeat++;
                    continue;
                }
                int g = gcd(dx, dy);  // 计算最大公约数
                if (g) {
                    dy /= g, dx /= g;
                }
                // 拼接键
                string key = to_string(dy) + '/' + to_string(dx);
                hash[key]++;
                // 更新固定当前点时的最大点数
                tmp = max(tmp, hash[key]);
            }
            // 更新答案，这儿需要加上重复的点数和固定的点(+1操作)
            res = max(res, repeat + tmp + 1);
        }
        return res;
    }

    int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
};