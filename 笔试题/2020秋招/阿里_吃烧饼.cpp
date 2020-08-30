#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    nums[0] = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x >= nums[i - 1])
            nums[i] = nums[i - 1];
        else
            nums[i] = x;
    }
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        res += nums[i];
    }
    cout << res << endl;
}