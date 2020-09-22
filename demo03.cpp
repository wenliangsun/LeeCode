#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int maxSubArray(vector<int>& nums) {
    int res = INT_MAX, last = 0, idx1 = 0, idx2 = 0, r = 0, l = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (last + nums[i] < nums[i]) {
            last += nums[i];
            idx2 = i;
            idx1 = l;
        } else {
            last = nums[i];
            idx1 = idx2 = i;
        }
        if (res > last) {
            res = last;
            l = idx1;
            r = idx2;
        }
    }
    cout << res << ' ' << l << ' ' << r << endl;
    return res;
}

struct Node {
    int a;
    float c;
    double b;
    char arr[17];
    static int d;
} AA;

static int val;

int fun() {
    static int num = 0;
    ++num;
    return num;
}

int fun2() {
    static int val = 0;
    ++val;
    return val;
}

int main() {
    for (int i = 0; i < 10; i++) {
        cout << fun2() << ' ';
    }
}