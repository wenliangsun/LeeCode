//
// Created by wenliangsun on 2020/2/12.
//

#ifndef C__ALGORITHM_NEWCODER32_H
#define C__ALGORITHM_NEWCODER32_H

#include <string>
#include <vector>
#include <algorithm>

#endif //C__ALGORITHM_NEWCODER32_H
using namespace std;

/**
 * 题目32：把数组排成最小的数
 * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
 * 打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，
 * 则打印出这三个数字能排成的最小数字为321323。
 */
class NewCoder32 {
public:
    /**思路：
     * 将整型数组转换成string数组排序，最后将排好序的字符串拼接起来
     * 排序规则：
     * 如果ab<ba, 则a<b; 32,321 , 32321 > 32132  所以 321小于32。
     * 如果ab>ba, 则a>b;
     * 如果ab=ba, 则a=b;
     *
     * 注意：排序规则是否有效，大数问题
     * @param numbers
     * @return
     */
    string PrintMinNumber(vector<int> numbers) {
        if (numbers.empty())
            return "";
        sort(numbers.begin(), numbers.end(), compare); // sort函数的用法！！
        string str;
        for (int i = 0; i < numbers.size(); i++) {
            str += to_string(numbers[i]); // 拼接字符串
        }
        return str;
    }

    static bool compare(int a, int b) { // 排序的规则！！！
        string A = to_string(a) + to_string(b);
        string B = to_string(b) + to_string(a);
        return A < B;
    }
};