#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string replaceSpace(string s) {
        string res;
        for (auto c : s) {
            if (c == ' ')
                res += "%20";
            else
                res.push_back(c);
        }
        return res;
    }
};