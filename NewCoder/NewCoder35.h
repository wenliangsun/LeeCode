//
// Created by wenliangsun on 2020/2/13.
//

#ifndef C__ALGORITHM_NEWCODER35_H
#define C__ALGORITHM_NEWCODER35_H

#include <vector>

#endif //C__ALGORITHM_NEWCODER35_H
using namespace std;

/**
 * 题目35：数组中的逆序对
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
 * 输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。
 * 即输出P%1000000007
 */
class NewCoder35 {
public:
    int InversePairs(vector<int> data) {
        int count = 0;
        for (int i = 0; i < data.size(); ++i) {
            for (int j = i; j < data.size(); ++j) {
                if (data[i] > data[j]) {
                    count++;
                }
            }
        }
        return count % 1000000007;
    }
};