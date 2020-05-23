//
// Created by wenliangsun on 2020/2/14.
//

#ifndef C__ALGORITHM_NEWCODER40_H
#define C__ALGORITHM_NEWCODER40_H

#include <vector>
#include <map>

#endif //C__ALGORITHM_NEWCODER40_H
using namespace std;

/**
 * 题目40：数组中只出现一次的数字
 * 一个整型数组里除了两个数字之外，其他的数字都出现了两次。
 * 请写程序找出这两个只出现一次的数字。
 */
class NewCoder40 {
public:
    /**
     * 思路：遍历数组，利用hash map 记录每一个数字出现的次数，
     * 然后找出出现次数为1的两个数字。
     */
    void FindNumsAppearOnce01(vector<int> data, int *num1, int *num2) {
        map<int, int> m; // 记录每个数字出现的次数
        vector<int> temp;
        for (int i = 0; i < data.size(); ++i) { // 统计每个数字出现的次数
            if (m.find(data[i]) != m.end()) {
                m[data[i]]++;
            } else {
                m[data[i]] = 1;
            }
        }

        for (int j = 0; j < data.size(); ++j) { // 寻找出现次数为1的数字
            if (m[data[j]] == 1) {
                temp.push_back(data[j]);
            }
        }
        *num1 = temp[0];
        *num2 = temp[1];
    }

    void FindNumsAppearOnce02(vector<int> data, int *num1, int *num2) {

    }

    /**
     * 数组中除了一个数字出现了一次外，其他数字均出现了两次，找出这个数字.
     * 思路：依次异或数组中的数字，最终得到的结果就是只出现一次的数字，因为出现两次的数字都相互抵消了
     * @param data
     * @param num1
     */
    void FindNumsAppearOnce(vector<int> data, int *num1) {
        int res = data[0];
        for (int i = 1; i < data.size(); ++i) {
            res ^= data[i];
        }
        *num1 = res;
    }
};