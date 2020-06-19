#include <bits/stdc++.h>

using namespace std;

/**
 * 题目566：重塑矩阵
 */

class Solution {
   public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size(), n = nums[0].size();
        if (n * m != r * c) return nums;
        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int idx = i * c + j;
                res[i][j] = (nums[idx / n][idx % n]);
            }
        }
        return res;
    }
};