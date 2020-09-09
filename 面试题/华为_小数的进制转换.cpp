#include <bits/stdc++.h>

using namespace std;

/**
 * 小数的进制转换
 */

int main() {
    float n;
    int digit;
    int pricision;
    cin >> n >> digit >> pricision;
    int cnt = 0;
    vector<int> res;
    while (n >= (1 / pow(digit, pricision))) {
        n = n * digit;
        int t = n;
        n = n - t;
        cnt++;
        res.push_back(t);
    }
    cout << "0.";
    for (auto t : res) cout << t;
}