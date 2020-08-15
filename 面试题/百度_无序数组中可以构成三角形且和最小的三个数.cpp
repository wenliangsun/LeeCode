#include <bits/stdc++.h>

using namespace std;

// 暴力
vector<int> triangle(vector<int>& nums) {
    int n = nums.size();
    vector<int> res;
    int sum = INT_MAX;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            for (int k = j + 1; k < n; k++) {
                if (nums[i] + nums[j] > nums[k] &&
                    nums[i] + nums[k] > nums[j] &&
                    nums[j] + nums[k] > nums[i]) {
                    if (sum > nums[i] + nums[j] + nums[k]) {
                        sum = nums[i] + nums[j] + nums[k];
                        res.push_back(nums[i]);
                        res.push_back(nums[j]);
                        res.push_back(nums[k]);
                    }
                }
            }
        }
    }
    return res;
}

vector<int> triangle(vector<int>& nums)  {
    
}

int main() {
    vector<int> nums = {1, 4, 5, 67, 3, 435, 54, 6, 676, 7};
    // sort(nums.begin(), nums.end());
    vector<int> res = triangle(nums);
    cout << res[0] << ' ' << res[1] << ' ' << res[2] << endl;
}