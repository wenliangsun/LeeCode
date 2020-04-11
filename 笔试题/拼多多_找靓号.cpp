#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef pair<char, int> PII;

const int N = 10010;

char nums[N];

int main() {
    int n, k;
    string nums;
    cin >> n >> k;
    cin >> nums;
    unordered_map<char, int> mp;
    for (int i = 0; i < n; i++) {
        mp[nums[i]]++;
    }
    vector<PII> times;
    for (int i = 0; i < n; i++) {
        times.push_back({mp[nums[i]], nums[i]});
    }
    sort(times.begin(), times.end());
    reverse(times.begin(), times.end());
    if (times[0].first >= k) {
        cout << 0 << endl;
        cout << nums << endl;
    }

    int res = 0;
    for (int i = 0; i < times.size(); i++) {
        PII t = times[i];
        char n = t.second;
        int count = t.first;
        char l = n - 1;
        char r = n + 1;
        while (l >= '0' || r <= '9') {
            int lcost = 0, rcost = 0;
            bool can = false;
            if (mp.count(l)) {
                if (count + mp[l] >= k) {
                    lcost = (k - count) * abs(n - l);
                    can = true;
                } else {
                    lcost = mp[l] * abs(n - l);
                    count += mp[l];
                }
            }
            if (can) {
            }
            if (mp.count(r)) {
                if (count + mp[r] >= k) {
                    rcost = (k - count) * abs(n - r);
                    can = true;
                } else {
                    rcost = mp[r] * abs(n - r);
                    count += mp[l];
                }
            }
            if (can) {
            }
            l--;
            r++;
        }
    }
    cout << res << endl;
    cout << nums << endl;
}