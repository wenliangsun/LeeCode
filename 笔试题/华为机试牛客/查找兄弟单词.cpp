#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<string> dict;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            dict.push_back(s);
        }
        string w;
        cin >> w;
        int idx;
        cin >> idx;
        vector<string> res;
        for (auto s : dict) {
            if (s != w) {
                string temps = s;
                string tempw = w;
                sort(temps.begin(), temps.end());
                sort(tempw.begin(), tempw.end());
                if (temps == tempw) {
                    res.push_back(s);
                }
            }
        }

        sort(res.begin(), res.end());
        cout << res.size() << endl;
        if (idx - 1 < res.size()) cout << res[idx - 1] << endl;
    }
    return 0;
}