#include <bits/stdc++.h>

using namespace std;

/**
 * 牛牛去犇犇老师家补课，出门的时候面向北方，但是现在他迷路了。虽然他手里有一张地图，但是他需要知道自己面向哪个方向，请你帮帮他。
 */

typedef pair<char, char> PII;

unordered_map<char, PII> m = {
    {'N', {'W', 'E'}}, {'E', {'N', 'S'}}, {'S', {'E', 'W'}}, {'W', {'S', 'N'}}};

int main() {
    int n;
    while (cin >> n) {
        string s;
        cin >> s;
        char cur = 'N';
        for (auto c : s) {
            if (c == 'L')
                cur = m[cur].first;
            else
                cur = m[cur].second;
        }
        cout << cur << endl;
    }
    return 0;
}