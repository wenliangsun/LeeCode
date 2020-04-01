//
// Created by wenliangsun on 2020/2/11.
//

#ifndef C__ALGORITHM_NEWCODER30_H
#define C__ALGORITHM_NEWCODER30_H

#include <vector>

#endif //C__ALGORITHM_NEWCODER30_H
using std::vector;

/**
 * 题目30:连续子数组的最大值
 * 6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
 * 给一个数组，返回它的最大连续子序列的和
 */
class NewCoder30 {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int curSum = 0;
        int maxSum = array[0];
        for (int i = 0; i < array.size(); ++i) {
            curSum += array[i];
            if (curSum < array[i]) {
                curSum = array[i];
            }
            if (curSum > maxSum)
                maxSum = curSum;
        }
        return maxSum;
    }
};