#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    // map<vector<int>, int> hash;
    // vector<int> t = {1, 2, 3};
    // vector<int> t2 = {1, 2, 4};
    // bool res = t==t2;
    // cout<<res<<endl;

    // vector<string> s;
    // s.push_back("");
    // cout << s.size();

    int res = gcd(4, 6);
    cout << res << endl;

    // string a = "aaabbb";
    // string b = "aaabbbccc";
    // bool res =  a < b;
    // cout << res << endl;

    // hash[t]++;
    // hash[t2]++;
    // cout << hash.size();

    // vector<int> v(10);
    // cout << v.capacity() << endl;
    // cout << v.size() << endl;
    // v.push_back(1);
    // cout << v.capacity() << endl;
    // cout << v.size() << endl;

    // string s1 = "aa12345b";
    // int a = stoi(s1);
    // cout << a << endl;
    // // string s2 = "556678";
    // int b[s1.size()] = {0};
    // for (int i = 0; i < s1.size(); i++) {
    //     cout << b[i] << ' ';
    // }
    // int dp[s1.size()][s2.size()] = {0};
    // for (int i = 0; i < s1.size(); i++) {
    //     for (int j = 0; j < s2.size(); j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    // char str1[100] = "Hello\0\0hello";
    // cout << str1 << endl;
    // char str2[100] = "Helloworld";
    // str2[4] = '\0';
    // cout << str2 << endl;
}