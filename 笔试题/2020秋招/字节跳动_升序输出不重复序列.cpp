#include <bits/stdc++.h>

using namespace std;

/**
 * 输入：1 2 2 3 3 3 4 5 6 6 7 8 9 8 7 6 6 6 5 4 3 2 1
 * 输出：1 2 3 4 5 6 7 8 9
 */

vector<int> split(string s, string p) {
    s += p;
    int pos = s.find(p);
    vector<int> res;
    while (pos != s.npos) {
        res.push_back(stoi(s.substr(0, pos)));
        s = s.substr(pos + 1);
        pos = s.find(p);
    }
    return res;
}

int main() {
    string s;
    getline(cin, s);
    vector<int> nums = split(s, ",");
    int l = 0, r = nums.size() - 1;
    string res;
    while (l <= r) {
        if (nums[l] < nums[r]) {
            if ((l == 0 || l > 0 && nums[l] != nums[l - 1]))
                res += to_string(nums[l]) + ',';
            l++;
        } else if (nums[l] > nums[r]) {
            if ((r == nums.size() - 1) ||
                (r < nums.size() - 1 && nums[r] != nums[r + 1]))
                res += to_string(nums[r]) + ',';
            r--;
        } else if (nums[l] == nums[r]) {
            if ((l == 0 || (l > 0 && nums[l] != nums[l - 1])))
                res += to_string(nums[l]) + ',';
            l++, r--;
        }
    }
    cout << res.substr(0, res.size() - 1) << endl;
    return 0;
}