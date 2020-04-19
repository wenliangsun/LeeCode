#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            nums.push_back(x);
        }
        sort(nums.begin(), nums.end());
        int f = nums[0];
        int idx = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != f) {
                idx++;
                f = nums[i];
                nums[idx] = nums[i];
            }
        }
        for (int i = 0; i <= idx; i++) {
            cout << nums[i] << endl;
        }
    }
}