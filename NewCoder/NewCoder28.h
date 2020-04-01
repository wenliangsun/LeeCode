//
// Created by wenliangsun on 2020/2/11.
//

#ifndef C__ALGORITHM_NEWCODER28_H
#define C__ALGORITHM_NEWCODER28_H

#include <vector>

#endif //C__ALGORITHM_NEWCODER28_H
using std::vector;

/**
 * 题目28：数组中出现次数超过一半的数字
 *  数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 *  例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
 *  由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
 *
 */
class NewCoder28 {
public:
    /**
     * 思路：如果一个数组出现的次数超过了数组的一半，那么该数字可以将数组中的其他数字全都抵消掉。
     * 遍历数组，遇到相同的数字，次数+1，遇到不同的数字，次数-1，次数为0时重新计数。
     * 注意：抵消完之后的保存的数字需要再遍历依次数组来保证其出现的次数大于数组的长度的一半。
     * @param numbers
     * @return
     */
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty())
            return 0;
        int result = numbers[0];
        int times = 1;
        for (int i = 0; i < numbers.size(); ++i) {
            if (times == 0) {
                result = numbers[i];
                times = 1;
            }
            if (numbers[i] == result)
                times++;
            else
                times--;
        }
        int count = 0;
        for (int j = 0; j < numbers.size(); ++j) {
            if (numbers[j] == result)
                count++;
        }
        if (count * 2 <= numbers.size())
            return 0;
        return result;
    }
};