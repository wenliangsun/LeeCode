#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string reverseWords(string s) {
        int k = 0;
        for (int i = 0; i < s.size(); i++) {
            while (i < s.size() && s[i] == ' ') i++;  // 去除前面的空格
            if (i == s.size()) break;
            int j = i;
            while (j < s.size() && s[j] != ' ') j++;  // 获取单词
            reverse(s.begin() + i, s.begin() + j);    // 翻转单词
            if (k) s[k++] = ' ';                      // 单词间添加空格
            while (i < j)
                s[k++] = s[i++];  // 把字符串复制到前面，让多余的空格在最后面
        }
        s.erase(s.begin() + k, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};