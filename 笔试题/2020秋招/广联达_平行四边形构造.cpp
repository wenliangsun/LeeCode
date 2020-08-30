#include <bits/stdc++.h>

using namespace std;

/**
 * 给出n条边，从中选出4条边，组成一个最大的平行四边形，输出平行四边形的面积。
 */

typedef long long LL;

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
        hash[x]++;
    }
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    LL a = -1, b = -1;
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            a = nums[i];
            break;
        }
    }
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] == nums[i + 1] && (nums[i] != a || hash[a] >= 4)) {
            b = nums[i];
            break;
        }
    }
    if (a == -1 || b == -1)
        cout << -1 << endl;
    else
        cout << a * b << endl;
    return 0;
}