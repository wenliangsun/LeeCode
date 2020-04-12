#include <algorithm>
#include <iostream>

using namespace std;

/**
 * 题目：我们知道每一个大于1的整数都一定是质数或者可以用质数的乘积来表示，如10=2*5。
 * 现在请设计一个程序，对于给定的一个(1，N] 之间的正整数（N取值不超过10万），
 * 你需要统计(1，N] 之间所有整数的质数分解后，所有质数个数的总个数。
 * 举例，输入数据为6，那么满足(1,6] 的整数为2，3，4，5，6，
 * 各自进行质数分解后为：2=>2，3=>3，4=>2*2，5=>5，6=>2*3。
 * 对应的质数个数即为1，1，2，1，2。最后统计总数为7
 */

/**
 * 统计每个数的质因数个数
 */
int countPrimes(int n) {
    int times = 0;
    for (int i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            n /= i;
            times++;
        }
        if (n == 1) break;
    }
    if (n > 1) times++;
    return times;
}

int main() {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 2; i <= n; i++) {
        res += countPrimes(i);
    }
    cout << res << endl;
}
