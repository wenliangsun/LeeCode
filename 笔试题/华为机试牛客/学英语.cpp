#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Jessi初学英语，为了快速读出一串数字，编写程序将数字转换成英文：
 * 如22：twenty two，123：one hundred and twenty three。
 */

typedef long long LL;

vector<string> hunds = {"thousand", "million", "billion"};
vector<string> twens = {"twenty", "thirty",  "forty",  "fifty",
                        "sixty",  "seventy", "eighty", "ninety"};
vector<string> tens = {"ten",      "eleven",  "twelve",  "thirteen",
                       "fourteen", "fifteen", "sixteen", "seventeen",
                       "eighteen", "nighteen"};
vector<string> ones = {"one", "two",   "three", "four", "five",
                       "six", "seven", "eight", "nine"};

string helper(LL n) {
    string res;
    if (n > 0 && n <= 9)
        res += ones[n - 1];
    else if (n >= 10 && n <= 19)
        res += tens[n % 10];
    else if (n >= 20 && n <= 99) {
        res += twens[n / 10 - 2];
        if (n % 10 == 0) return res;
        res += ' ';
        res += ones[n % 10 - 1];
    } else {
        res += ones[n / 100 - 1];
        res += " hundred";
        n %= 100;
        if (n) {
            res += " and ";
            res += helper(n);
        }
    }
    return res;
}

int main() {
    LL n;
    while (cin >> n) {
        vector<LL> tmp;
        string res;
        if (n == 0) {
            cout << "error" << endl;
            continue;
        }
        if (n > 999999999 || n < 0) {
            cout << "error" << endl;
            continue;
        }
        while (n) {
            int t = n % 1000;
            tmp.push_back(t);
            n /= 1000;
        }
        for (int i = tmp.size() - 1; i >= 0; i--) {
            string st = helper(tmp[i]);
            res += st;
            if (i) {
                res += ' ';
                res += hunds[i - 1];
                res += ' ';
            }
        }
        cout << res << endl;
    }

    return 0;
}