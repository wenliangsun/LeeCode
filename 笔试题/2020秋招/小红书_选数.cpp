#include <bits/stdc++.h>

using namespace std;

int n, k, res;

bool isPrime(int n) {
    for (int i = 2; i < sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void count(vector<int>& nums, int idxn, int idxk, int sum) {
    if (idxn == n || idxk == k) {
        if (isPrime(sum) && idxk == k) res++;
        return;
    }
    count(nums, idxn + 1, idxk + 1, sum + nums[idxn]); // 添加当前数
    count(nums, idxn + 1, idxk, sum); // 不添加当前数
}

int main() {
    /**
     * 4 3
     * 3 7 12 19
     * 
     * 1
     */
    // cin >> n >> k;
    // vector<int> nums(n);
    // for (int i =0; i < n; i++) cin >> nums[i];
    n = 4, k = 3;
    vector<int> nums = {3, 7, 12, 19};
    count(nums, 0, 0, 0);
    cout << res << endl;
    return 0;
}