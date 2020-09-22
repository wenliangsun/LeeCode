#include <bits/stdc++.h>

using namespace std;

/**
 * 题目459：重复的子字符串
 */

class Solution {
   public:
    /**
     * 把字符串再拼一个，去掉头和尾的字符
     * 然后去找拼接后的字符串中是否有原来的字符串
     */
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        t = t.substr(1, t.size() - 2);
        return t.find(s) != t.npos;
    }
};