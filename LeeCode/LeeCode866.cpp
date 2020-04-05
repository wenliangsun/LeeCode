#include <algorithm>
#include <iostream>

using namespace std;

/**
 * 题目866：回文素数
 */
class LeeCode866 {
   public:
    int primePalindrome(int N) {
        while (true) {
            if (N == reverse(N) && isPrime(N)) {
                return N;
            }
            N++;
            // 如果当前数字长度是8，则跳过，因为不存在长度为8的素数
            if (N > 10000000 && N < 100000000) {
                N = 100000000;
            }
        }
    }

   private:
    // 翻转数字
    int reverse(int num) {
        int res = 0;
        while (num != 0) {
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }

    // 判断是否是素数
    bool isPrime(int num) {
        if (num < 2) {
            return false;
        }
        int n = sqrt(num);
        for (int i = 2; i <= n; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
};