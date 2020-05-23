#include <bits/stdc++.h>

using namespace std;

/**
 * 题目384：打乱数组
 */

class Solution {
    vector<int> data;

   public:
    Solution(vector<int>& nums) { data = nums; }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() { return data; }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> tmp = data;
        for (int i = 0; i < tmp.size(); i++) {
            int r = rand() % tmp.size();
            if (i != r) swap(tmp[i], tmp[r]);
        }
        return tmp;
    }
};