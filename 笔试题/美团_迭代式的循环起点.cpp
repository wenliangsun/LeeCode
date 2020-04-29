#include <iostream>
#include <map>

using namespace std;

/**
 * 给a,b,x,m四个数，给定递推式 x = (a * x + b ) % m，
 * 这个x不停算会循环，问递推第几次起x开始循环。
 */

typedef long long LL;

int main() {
    LL a, b, m, x;
    cin >> a >> b >> m >> x;
    map<LL, int> mp;
    int res = 0;
    while (true) {
        x = (a * x + b) % m;
        if (mp.count(x)) {
            cout << res << endl;
            break;
        }
        mp[x]++;
        res++;
    }
    return 0;
}