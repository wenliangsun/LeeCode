#include <bits/stdc++.h>

using namespace std;

/**
 * 题目717:1比特与2比特字符
 */

class Solution {
   public:
    /**
     * 线性扫描，遇到1向右移动两次，遇到0向右移动一次判断最后是否剩余移动一次
     */
    bool isOneBitCharacter(vector<int>& bits) {
        int idx = 0;
        while (idx < bits.size() - 1) {
            idx += bits[idx] + 1;
        }
        return idx == bits.size() - 1;
    }
};