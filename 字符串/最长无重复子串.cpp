#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    while (cin >> s) {
        // 双指针方法
        unordered_map<char, int> hash;
        int res = 0;
        for (int i = 0, j = 0; i < s.size(); i++) {
            hash[s[i]]++;
            while (hash[s[i]] > 1) hash[s[j++]]--;
            res = max(res, i - j + 1);
        }
        cout << res << endl;
    }
    return 0;
}