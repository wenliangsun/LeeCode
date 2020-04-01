//
// Created by wenliangsun on 2020/2/11.
//

#ifndef C__ALGORITHM_NEWCODER29_H
#define C__ALGORITHM_NEWCODER29_H

#include <vector>
#include <algorithm>

#endif //C__ALGORITHM_NEWCODER29_H
using std::vector;
using std::sort;

/**
 * 题目29：最小的K个数
 * 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
 */
class NewCoder29 {
    /**
     * 思路1：先对数组进行排序，然后取前k个数。
     * @param input
     * @param k
     * @return
     */
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.size()<k)
            return res;
        sort(input.begin(), input.end());
        for (int i = 0; i < k; ++i) {
            res.push_back(input[i]);
        }
        return res;
    }
};