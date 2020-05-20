#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    unordered_map<string, int> word;
    string w;
    while (cin >> w) word[w]++;

    int wordlen = w.size();
    int len = word.size() * wordlen;
    for (int i = 0; i < s.size() - len + 1; i++) {
        unordered_map<string, int> window;
        int nums = 0;
        while (nums < word.size()) {
            string t = s.substr(i + nums * wordlen, wordlen);
            if (!word.count(t)) break;
            if (window.count(t) && window[t] + 1 <= word[t])
                window[t]++;
            else
                break;
            nums++;
        }
        if (nums == word.size()) cout << i << endl;
    }
    return 0;
}