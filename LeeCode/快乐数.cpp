#include <bits/stdc++.h>

using namespace std;

/**
 * 题目202：快乐数
 */

class Solution {
   public:
    bool isHappy(int n) {
        unordered_set<int> hash;
        while (n != 1) {
            int t = 0;
            while (n) {
                t += pow(n % 10, 2);
                n /= 10;
            }
            if (hash.find(t) != hash.end()) {
                return false;
            }
            hash.insert(t);
            n = t;
        }
        return true;
    }
};