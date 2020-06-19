#include <bits/stdc++.h>

using namespace std;

/**
 * 题目414：第三大的数
 */

class Solution {
   public:
    int thirdMax(vector<int>& nums) {
        map<int, int> hash;
        for (auto n : nums) hash[n]++;
        map<int, int>::iterator it;
        it = hash.end();
        if (hash.size() < 3) return (*--it).first;
        for (int i = 0; i < 3; i++) it--;
        return (*it).first;
    }
};