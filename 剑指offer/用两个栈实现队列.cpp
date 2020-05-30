#include <bits/stdc++.h>

using namespace std;

class CQueue {
   public:
    stack<int> s1;
    stack<int> s2;
    CQueue() {}

    void appendTail(int value) { s1.push(value); }

    int deleteHead() {
        if (s2.empty()) {
            while (s1.size()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.size()) {
            int t = s2.top();
            s2.pop();
            return t;
        }
        return -1;
    }
};