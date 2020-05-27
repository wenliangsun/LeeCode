#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * 小Q十分富有，拥有非常多的硬币，小Q拥有的硬币是有规律的，对于所有的非负整数K，
 * 小Q恰好各有两个面值为2^K的硬币，所以小Q拥有的硬币就是1,1,2,2,4,4,8,8,…。
 * 小Q有一天去商店购买东西需要支付n元钱，
 * 小Q想知道有多少种方案从他拥有的硬币中选取一些拼凑起来恰好是n元
 * （如果两种方案某个面值的硬币选取的个数不一样就考虑为不一样的方案）
 *
 * 输入包括一个整数n(1≤n≤10^18)，表示小Q需要支付多少钱。注意n的范围。
 * 输出一个整数，表示小Q可以拼凑出n元钱放的方案数。
 */

typedef long long LL;

unordered_map<LL, LL> m;

LL helper(LL n) {
    if (m.count(n)) return m[n];
    LL cnt = helper(n / 2) + ((n % 2) ? 0 : helper(n / 2 - 1));
    m[n] = cnt;
    return cnt;
}

int main() {
    LL n;
    while (cin >> n) {
        m[0] = 1, m[1] = 1;
        cout << helper(n) << endl;
    }
    return 0;
}