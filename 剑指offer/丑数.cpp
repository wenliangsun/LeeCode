#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 思路：不能直接依次生成数字，然后判断是否是丑数
     * 我们依次生成从小到大的丑数
     * 考虑到后面的丑数是前面的丑数乘以2,3,5得到的，可以对当前的丑数分别乘以2,3,5。然后取大于当前生成的最大丑数中的最小丑数。
     * 此时，考虑已生成的丑数在前面的某个位置之后的丑数乘以2获得的丑数会大于当前生成的丑数，我们记录这个位置。
     * 同样，3和5也有类似的位置，因此我们分别记录这三个位置，然后分别乘以2,3,5取其中的最小值
     * 再更新这三个位置
     */
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;
        vector<int> tmp(n);
        tmp[0] = 1;
        int idx = 1;
        int idx2 = 0, idx3 = 0, idx5 = 0;
        while (idx < n) {
            tmp[idx] = min(tmp[idx2] * 2,
                           min(tmp[idx3] * 3, tmp[idx5] * 5));  // q取最小
            while (tmp[idx2] * 2 <= tmp[idx]) idx2++;  //更新2的位置
            while (tmp[idx3] * 3 <= tmp[idx]) idx3++;  //更新3的位置
            while (tmp[idx5] * 5 <= tmp[idx]) idx5++;  //更新5的位置
            idx++;
        }
        return tmp[n - 1];
    }
};