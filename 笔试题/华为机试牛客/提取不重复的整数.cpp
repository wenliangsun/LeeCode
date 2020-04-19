#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * 输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。
 */

int main() {
    int n;
    cin >> n;
    string num = to_string(n);
    unordered_map<char, int> mp;
    int res = 0;
    for (int i = num.size() - 1; i >= 0; i--) {
        if (!mp.count(num[i])) {
            res = res * 10 + num[i] - '0';
            mp[num[i]]++;
        }
    }
    cout << res << endl;
}