#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 一步一步判断！！！
     */
    bool isNumber(string s) {
        if (s.empty()) return false;
        int idx = 0;
        while (s[idx] == ' ') idx++;                // 去空格
        if (s[idx] == '+' || s[idx] == '-') idx++;  // 判断符号
        int n_dot, n_num;                           // 记录小数点和数字
        for (n_dot = 0, n_num = 0;
             (s[idx] >= '0' && s[idx] <= '9') || s[idx] == '.'; idx++)
            s[idx] == '.' ? n_dot++ : n_num++;
        if (n_dot > 1 || n_num < 1)
            return false;  // 小数点大于1或者数字小于1不和法
        if (s[idx] == 'e' || s[idx] == 'E') {  // 如果有e
            idx++;
            if (s[idx] == '+' || s[idx] == '-') idx++;  // 判断e之后的符号
            n_num = 0;  // 记录e之后的数字
            for (; s[idx] >= '0' && s[idx] <= '9'; idx++) n_num++;
            if (n_num < 1) return false;  // 如果数字小于1 不合法
        }
        while (s[idx] == ' ') idx++;  // 去空格
        return idx == s.size();
    }
};