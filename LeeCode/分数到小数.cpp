#include <bits/stdc++.h>

using namespace std;

/**
 * 题目166：分数到小数
 */

class Solution {
   public:
    // 模拟题
    string fractionToDecimal(int numerator, int denominator) {
        if (!denominator) return "";  // 边界情况
        if (!numerator) return "0";
        string res;
        // 转换成long long
        long long num = (long long)numerator;
        long long denom = (long long)denominator;
        // 处理符合
        if (num > 0 ^ denom > 0) res.push_back('-');
        // 全部转换成正数
        num = llabs(num), denom = llabs(denom);
        // 正数部分
        res += to_string(num / denom);
        num %= denom;
        // 如果整除，直接返回
        if (!num) return res;
        res += '.';
        // 小数部分索引
        int idx = res.size() - 1;
        // 记录是否重复
        unordered_map<int, int> hash;
        // 没有出现重复就一直计算余数
        while (num && hash.count(num) == 0) {
            hash[num] = ++idx;
            num *= 10;
            res += to_string(num / denom);
            num %= denom;
        }
        if (hash.count(num) == 1) {
            res.insert(hash[num], "(");
            res += ")";
        }
        return res;
    }
};