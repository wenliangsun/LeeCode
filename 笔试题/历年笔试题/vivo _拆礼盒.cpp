#include <bits/stdc++.h>

using namespace std;

/**
 * Welcome to vivo !
 */

/**
 * 考察括号的合法性
 */
int solution(string str) {
    int sum = 0;
    int t1 = 0;
    for (auto c : str) {
        if (c == '(')
            t1++;
        else if (c == ')')
            t1--;
        else if (c == '0')
            break;
    }
    int t2 = 0;
    for (int i = str.size() - 1; i >= 0; i--) {
        char c = str[i];
        if (c == ')')
            t2++;
        else if (c == '(')
            t2--;
        else if (c == '0')
            break;
    }
    sum = min(t1, t2);
    return sum;
}

int main() {
    string str("");
    getline(cin, str);

    int sum = solution(str);
    cout << sum << endl;
    return 0;
}