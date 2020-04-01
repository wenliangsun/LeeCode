//
// Created by wenliangsun on 2020/2/11.
//

#ifndef C__ALGORITHM_NEWCODER27_H
#define C__ALGORITHM_NEWCODER27_H

#include <vector>
#include <string>
#include<algorithm>

#endif //C__ALGORITHM_NEWCODER27_H
using std::vector;
using std::string;
using std::find;
using std::sort;

/**
 * 题目27：字符串序列
 * 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
 * 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba
 */
class NewCoder27 {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if (str.empty())
            return res;
        permutation(str, 0, res);
        sort(res.begin(), res.end()); // 这儿排序是为了调整成字典顺序
        return res;
    }

    /**
     * 使用递归的思想！
     * 首先遍历第一个位置上可能出现的字符，
     * 固定第一个字符，求后面字符的排列。
     * @param str
     * @param begin
     * @param res
     */
    void permutation(string &str, int begin, vector<string> &res) {
        if (begin == str.size() - 1) {
            // 去重复
            if (find(res.begin(), res.end(), str) == res.end())
                res.push_back(str);
        } else {
            for (int i = begin; i < str.size(); ++i) {
                char temp = str[i];
                str[i] = str[begin];
                str[begin] = temp;
                permutation(str, begin + 1, res);
                temp = str[i];
                str[i] = str[begin];
                str[begin] = temp;
            }
        }
    }
};