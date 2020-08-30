#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        int idx = 0, cnt = 0;
        while (idx < nums.size()) {
            // 当前位置可以种花的条件
            if (nums[idx] == 0 && (idx == 0 || nums[idx - 1] == 0) &&
                (idx == nums.size() - 1 || nums[idx + 1] == 0)) {
                nums[idx] = 1;
                cnt++;
            }
            idx++;
        }
        cout << cnt << endl;
    }
    return 0;
}