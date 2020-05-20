#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * 从0,1,2,...,n这n+1个数中选择n个数，找出这n个数中缺失的那个数，要求O(n)尽可能小
 */

int main() {
    string s;
    cin >> s;

    // C++中分割字符串的方法
    s += ',';
    vector<int> nums;
    int pos = s.find(',');
    while (pos != s.npos) {
        string temp = s.substr(0, pos);
        nums.push_back(stoi(temp));
        s = s.substr(pos + 1);
        pos = s.find(',');
    }
    sort(nums.begin(), nums.end());
    int index = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        if (index != nums[i]) {
            cout << index << endl;
            break;
        }
        index++;
    }
}
