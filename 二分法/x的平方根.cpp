#include <iostream>

using namespace std;

typedef long long LL;

/**
 * x的平方根
 */

class Solution {
   public:
    int mysqrt(int x) {
        int l = 0, r = x;
        while (l < r) {
            int mid = (LL)l + r + 1 >> 1;
            if (mid <= x / mid)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};

int main() {
    Solution s = Solution();
    int res = s.mysqrt(4);
    cout << res << endl;
}