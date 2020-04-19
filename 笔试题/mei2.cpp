#include <iostream>
#include <map>

using namespace std;

int main() {
    int a, b, m, x;
    cin >> a >> b >> m >> x;
    map<int, int> mp;
    map<int, int> mp2;
    int res = 0;
    while (true) {
        x = (a * x + b) % m;
        res++;
        if (mp.count(x) && mp2.count((a * x + b) % m)) {
            cout << res - 1 << endl;
            break;
        }
        mp[x]++;
        mp2[(a * x + b) % m]++;
    }

    return 0;
}