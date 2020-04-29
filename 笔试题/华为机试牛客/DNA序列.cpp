#include <iostream>
#include <string>

using namespace std;

/**
 * 一个DNA序列由A/C/G/T四个字母的排列组合组成。G和C的比例（定义为GC-Ratio）
 * 是序列中G和C两个字母的总的出现次数除以总的字母数目（也就是序列长度）。
 * 在基因工程中，这个比例非常重要。因为高的GC-Ratio可能是基因的起始点。
 * 给定一个很长的DNA序列，以及要求的最小子序列长度，
 * 研究人员经常会需要在其中找出GC-Ratio最高的子序列。
 */

int main() {
    string s;
    int n;

    while (cin >> s >> n) {
        int cnt = 0, mx = 0, l = 0, r = 0;
        string ans;
        while (r < s.size()) {
            if (r - l < n - 1) {
                if (s[r] == 'G' || s[r] == 'C') cnt++;
                r++;
            } else {
                if (cnt > mx) {
                    mx = cnt;
                    ans = s.substr(l, n);
                }
                if (s[l] == 'G' || s[l] == 'C') cnt--;
                l++, r++;
                if (s[r] == 'G' || s[r] == 'C') cnt++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}