#include <bits/stdc++.h>

using namespace std;

/**
 * 题目1431：拥有最多糖果的孩子
 */

class Solution {
   public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = 0;
        for (auto ca : candies) mx = max(mx, ca);
        vector<bool> res;
        for (auto ca : candies)
            if (ca + extraCandies >= mx)
                res.push_back(true);
            else
                res.push_back(false);

        return res;
    }
};