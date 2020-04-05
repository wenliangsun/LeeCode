#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目：高效寻找素数
 */
class FindSuShu {
   public:
    int countPrimes(int N) {
        vector<bool> isPrime(N + 1, true);
        // 判断一个数n是否是素数，只需要判断[1,sqrt(n)]中有没有可整除因子
        for (int i = 2; i * i <= N; i++) {
            if (isPrime[i]) {
                // 如果当前值是素数，那么它的倍数肯定不是素数，注意这儿从平方开始
                for (int j = i * i; j <= N; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        int count = 0;
        for (int i = 2; i <= N; i++) {
            if (isPrime[i]) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    FindSuShu s = FindSuShu();
    int res = s.countPrimes(5);
    cout << res << endl;
}