#include <algorithm>
#include <iostream>

using namespace std;

/**
 * 买商品，买三送一，送价钱最低的，准备买n个商品（编号1-n），
 * 其中第i个商品的价格为Ai，现在找到策略，花最少的钱买到所有商品。
 */

const int N = 100010;
int n;
int p[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p, p + n);
    reverse(p, p + n);
    int cost = 0;
    int count = 0;
    int index = 0;
    while (index < n) {
        cost += p[index];
        count++;
        if (count == 3) {
            cost -= p[index];
            count = 0;
        }
        index++;
    }
    cout << cost << endl;
}