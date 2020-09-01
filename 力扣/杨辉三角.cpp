#include <vector>

using namespace std;

/**
 * 题目118：杨辉三角
 */

class Solution {
   public:
    /**
     * 由上一层相加得到
     */
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++) {
            vector<int> tmp;
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) // 两端的时候直接填充1
                    tmp.push_back(1);
                else
                    tmp.push_back(res[i - 1][j - 1] + res[i - 1][j]); // 上一层的相加
            }
            res.push_back(tmp);
        }
        return res;
    }
};