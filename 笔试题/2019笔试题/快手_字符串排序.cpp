#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * 月神拿到一个新的数据集，其中每个样本都是一个字符串（长度小于100），
 * 样本的的后六位是纯数字，月神需要将所有样本的后六位数字提出来，转换成数字，
 * 并排序输出。
 */

int main() {
    int T;
    cin >> T;
    vector<string> nums;
    while (T--) {
        string s;
        cin >> s;
        nums.push_back(s.substr(s.size() - 6));
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
}