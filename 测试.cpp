#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

bool isSqrt(int n) {
    if (!n) return true;
    int l = 1, r = n;
    while (l < r) {
        int mid = l + r + 1ll >> 1;
        if ((long)mid * mid < n)
            l = mid;
        else
            r = mid - 1;
    }
    return l * l == n;
}

bool isSqrt2(int n) {
    for (int i = 1; n > 0; i += 2) {
        n -= i;
    }
    return n == 0;
}



int main() {
    string s = "abcbcbacbcdacb";
    int m = 0;
    for (char c : s) {
        if (m & (1 << (c - 'a'))) {
            cout << "False" << endl;
            break;
        }
        m |= (1 << (c - 'a'));
        cout << m << endl;
    }
    return 0;
}