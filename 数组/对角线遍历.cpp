#include <bits/stdc++.h>

using namespace std;

/**
 * 题目498：对角线遍历
 */

class Solution {
   public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (!matrix.size() || !matrix[0].size()) return res;
        int m = matrix.size(), n = matrix[0].size();
        bool d = true;
        for (int i = 0; i < m + n; i++) {
            int pm = d ? m : n;
            int pn = d ? n : m;
            int x = i < pm ? i : pm - 1;
            int y = i - x;
            while (x >= 0 && y < pn) {
                res.push_back(d ? matrix[x][y] : matrix[y][x]);
                x--;
                y++;
            }
            d = !d;
        }
        return res;
    }
};