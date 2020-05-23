//
// Created by wenliangsun on 2020/2/14.
//

#ifndef C__ALGORITHM_NEWCODER41_H
#define C__ALGORITHM_NEWCODER41_H

#include <vector>

#endif //C__ALGORITHM_NEWCODER41_H
using namespace std;

/**
 * 题目41：和为S的连续正数序列
 * 输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
 */
class NewCoder41 {
public:
    /**
     * 思路：一般求一个序列的累积和是使用一个循环来计算，但是这样导致我们每计算一个序列就需要循环计算，导致一些序列重复计算，
     * 因此，我们可以考虑利用前面的计算结果来求之后的序列和。
     * @param sum
     * @return
     */
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int >> res;
        if (sum < 3)
            return res;
        int small = 1; // 序列的开始数字
        int big = 2; // 序列的结束数字
        int mid = (1 + sum) / 2; // 序列的开始数字要小于中间的数字,因为序列至少包含两个数字
        int curSum = small + big;
        while (small < mid) { // 注意这儿的条件！！！
            if (curSum == sum) { // 如果序列的累计和和sum相等，则将该序列添加到结果中
                // 将从small到big的序列添加进res中
                vector<int> temp;
                for (int i = small; i <= big; ++i) {
                    temp.push_back(i);
                }
                res.push_back(temp);
            }
            if (curSum > sum) { // 如果序列和大于sum，则减去序列中最小的数字，即small指针后移
                curSum -= small;
                small++;
            } else { // 如果序列和不大于sum，则将序列中最大值+1，即big指针后移。
                big++;
                curSum += big;
            }
        }
        return res;
    }
};