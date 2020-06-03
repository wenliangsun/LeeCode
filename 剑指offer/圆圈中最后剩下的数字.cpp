#include <bits/stdc++.h>

using namespace std;

/**
 * 圆圈中最后剩下的数字
 */

class Solution {
   public:
    int lastRemaining(int n, int m) {
        if (n < 1 || m < 1) return -1;
        list<int> nums;
        // 构建循环链表
        for (int i = 0; i < n; i++) nums.push_back(i);
        list<int>::iterator cur = nums.begin();
        while (nums.size() > 1) {
            // 寻找下一个出队的位置
            for (int i = 1; i < m; i++) {
                cur++;
                if (cur == nums.end()) cur = nums.begin();
            }
            // 记录下一个位置
            list<int>::iterator next = ++cur;
            if (next == nums.end()) next = nums.begin();
            cur--;
            // 当前位置出队
            nums.erase(cur);
            cur = next;
        }
        return *cur;
    }

    /**
     * 数学法
     */
    int lastRemaining(int n, int m) {
        int res = 0;
        for (int i = 2; i <= n; i++) {
            res = (res + m) % i;
        }
        return res;
    }
};