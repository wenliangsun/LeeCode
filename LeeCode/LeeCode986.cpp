#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目986：区间列表的交集
 */
class LeeCode986 {
   public:
    /**
     * 思路：双指针法
     */
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A,
                                             vector<vector<int>>& B) {
        vector<vector<int>> res;
        int n_A = A.size();
        int n_B = B.size();
        int i = 0;
        int j = 0;
        while (i < n_A && j < n_B) {
            // 有交集
            if (A[i][1] >= B[j][0] && A[i][0] <= B[j][1]) {
                vector<int> temp;
                temp.push_back(max(A[i][0], B[j][0]));
                temp.push_back(min(A[i][1], B[j][1]));
                res.push_back(temp);
            }
            if (A[i][1] < B[j][1]) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};