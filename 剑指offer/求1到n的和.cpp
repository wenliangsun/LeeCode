#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int sumNums(int n) {
        int res = n;
        bool t = (n > 0) && ((res += sumNums(n - 1)) > 0);
        return res;
    }
};