#include <iostream>

using namespace std;

/**
 * 美团题目：小王是个爱健身的小伙，每天去n*n的场地跑步，他有强迫症，
 * 每跑n+1就要做个标记，当他在一个点重复标记的时候，停止锻炼，问每天要打多少个标记？
 * 设当标记到起点的时候打了x个标记，此时跑了y圈，则有
 * (n+1)*x = 4n*y
 * x = [n+1,4n]/(n+1)   [n+1,4n]*(n+1,4n) = (n+1)*(4n)
 */

/**
 * 求两个数的最大公约数 其中 a>b
 * 时间复杂度：O(log(n))
 */
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

/**
 * 两个数的最小公倍数 * 两个数的最大公约数 = a*b a>b
 */
int lcm(int a, int b) { return a * b / gcd(a, b); }

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int d = gcd(4 * n, n + 1);
        cout << 4 * n / d + 1 << endl;
    }
    return 0;
}