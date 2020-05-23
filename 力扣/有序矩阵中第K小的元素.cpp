#include <bits/stdc++.h>

using namespace std;

/**
 * 题目378：有序矩阵中的第K小的元素
 */

class Solution {
   public:
    /**
     * 二分查找  套用模板
     */
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n - 1][n - 1];
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(matrix, mid) < k)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }

    // 统计小于mid的个数
    int check(vector<vector<int>>& matrix, int mid) {
        int cnt = 0, n = matrix.size();
        int x = 0, y = n - 1;
        while (x < n && y >= 0) {
            if (matrix[x][y] < mid) {
                cnt += y + 1;
                x++;
            } else {
                y--;
            }
        }
        return cnt;
    }

    /**
     * 使用优先队列 未考虑排序的信息
     *
     * 时间复杂度：O(n^2)
     * 空间复杂度：O(n)
     */
    int kthSmallest1(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                q.push(matrix[i][j]);
            }
        }
        for (int i = 0; i < k - 1; i++) {
            q.pop();
        }
        return q.top();
    }
};