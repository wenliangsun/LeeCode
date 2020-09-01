#include <bits/stdc++.h>

using namespace std;

/**
 * 题目119：杨辉三角II
 */

class Solution {
   public:
    /**
     * 空间还可以优化
     */ 
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        for (int i = 0; i <= rowIndex; i++) {
            vector<int> tmp;
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i)
                    tmp.push_back(1);
                else
                    tmp.push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }
            res.push_back(tmp);
        }
        return res[rowIndex];
    }
};