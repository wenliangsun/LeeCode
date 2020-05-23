//
// Created by wenliangsun on 2020/2/13.
//

#ifndef C__ALGORITHM_NEWCODER37_H
#define C__ALGORITHM_NEWCODER37_H

#include <vector>

#endif //C__ALGORITHM_NEWCODER37_H
using namespace std;

/**
 * 题目37：数字在排序数组中出现的次数
 * 统计一个数字在排序数组中出现的次数。
 */
class NewCoder37 {
public:
    /**
     * 思路1：采用二分查找，找到K，然后统计k前面和k后面出现的次数
     * @param data
     * @param k
     * @return
     */
    int GetNumberOfK01(vector<int> data, int k) {
        int start = 0;
        int end = data.size() - 1;
        int mid;
        while (start <= end) { // 二分查找终止条件
            mid = (start + end) / 2;
            if (data[mid] == k)
                break;
            if (data[mid] < k)
                start = mid + 1;
            if (data[mid] > k)
                end = mid - 1;
        }
        if (start > end)
            return 0;
        int count = 1;
        int index = mid + 1;
        while (data[index] == k) {
            count++;
            index++;
        }
        index = mid - 1;
        while (data[index] == k) {
            count++;
            index--;
        }
        return count;
    }

    int GetNumberOfK02(vector<int> data, int k) {

    }
};