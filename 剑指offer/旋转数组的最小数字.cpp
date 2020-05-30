#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 二分法模板题
     * 需要考虑里面有重复数字的问题
     */
    int minArray(vector<int>& numbers) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (numbers[mid] < numbers[r])
                r = mid;
            else if (numbers[mid] > numbers[r])
                l = mid + 1;
            else
                r--;
        }
        return numbers[l];
    }
};