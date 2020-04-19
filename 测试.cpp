#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // vector<int> v(10);
    // cout << v.capacity() << endl;
    // cout << v.size() << endl;
    // v.push_back(1);
    // cout << v.capacity() << endl;
    // cout << v.size() << endl;

    string s1 = "aa12345b";
    int a = stoi(s1);
    cout << a << endl;
    // string s2 = "556678";
    int b[s1.size()] = {0};
    for (int i = 0; i < s1.size(); i++) {
        cout << b[i] << ' ';
    }
    // int dp[s1.size()][s2.size()] = {0};
    // for (int i = 0; i < s1.size(); i++) {
    //     for (int j = 0; j < s2.size(); j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
}