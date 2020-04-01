//
// Created by wenliangsun on 2020/2/13.
//

#ifndef C__ALGORITHM_NEWCODER34_H
#define C__ALGORITHM_NEWCODER34_H

#include <string>
#include <map>

#endif //C__ALGORITHM_NEWCODER34_H
using namespace std;

/**
 * 题目34：第一个只出现一次的字符
 * 在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
 * 并返回它的位置, 如果没有则返回 -1（需要区分大小写
 */
class NewCoder34 {
public:
    /**
     * 思路：遍历字符串中的每一个字符，然后利用哈希表记录每一个字符出现的次数；
     * 遍历字符串返回出现次数为1的字符的下标。
     * @param str
     * @return
     */
    int FirstNotRepeatingChar(string str) {
        if (str.empty())
            return -1;
        map<char, int> m;
        for (int i = 0; i < str.size(); ++i) { // 统计每个字符出现的次数
            if (m.find(str[i]) != m.end()) { // 为出现的字符的次数+1
                m[str[i]]++;
            } else {
                m[str[i]] = 1; // 如果哈希表中没有这个字符，则添加
            }
        }
        int index = 0;
        for (int j = 0; j < str.size(); ++j) { // 寻找第一个统计出现次数为1的字符下标
            if (m[str[j]] == 1) {
                index = j;
                break;
            }
        }
        return index;
    }
};