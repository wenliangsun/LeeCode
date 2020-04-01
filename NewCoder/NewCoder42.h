//
// Created by wenliangsun on 2020/2/14.
//

#ifndef C__ALGORITHM_NEWCODER42_H
#define C__ALGORITHM_NEWCODER42_H

#include <vector>

#endif //C__ALGORITHM_NEWCODER42_H
using namespace std;

/**
 * 题目42：和为s的两个数字
 * 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
 * 如果有多对数字的和等于S，输出两个数的乘积最小的。
 */
class NewCoder42 {
public:
    /**
     * 思路：设定两个指针，一个指向数组中的最小的数字，一个指向数组中的最大的数字
     * 如果两个指针的和小于sum，则将指向最小数的指针向右移动
     * 如果两个指针的和大于sum，则将指向最大数的指针向左移动。
     * 如果相等则判断其乘积是否是最小的。
     * @param array
     * @param sum
     * @return
     */
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        vector<int> res;
        if (array.size() < 2)
            return res;
        int small = 0; // 指向最小的数
        int big = array.size() - 1; // 指向最大的数
        int minMultiply = 10000000; // 记录相乘最小的结果
        int num1Index = -1; // 记录第一个数
        int num2Index = -1; // 记录第二个数
        while (small < big) {
            int curSum = array[small] + array[big];
            int multi = array[small] * array[big];
            if (curSum == sum) { // 如果相等，更新这两个数
                if (multi < minMultiply) {
                    num1Index = small;
                    num2Index = big;
                    minMultiply = multi;
                }
            }
            if (curSum < sum) // 如果小于sum，则最小数指针右移
                small++;
            else // 如果大于sum，则最大数指针左移
                big--;
        }
        if (num1Index != -1 && num2Index != -1) { // 判断是否存在两个数的和为sum
            res.push_back(array[num1Index]);
            res.push_back(array[num2Index]);
        }
        return res;
    }
};