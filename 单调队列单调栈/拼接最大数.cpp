#include <bits/stdc++.h>

using namespace std;

/**
 * 题目321：拼接最大数
 */

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        stack<int> stk1, stk2;
        for (int i = nums1.size() - 1; i >= 0; i--) {
            while (k && stk1.size() && stk1.top() > nums1[i]) {
                stk1.pop();
                k--;
            }
            stk1.push(nums1[i]);
        }
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (k && stk1.size() && stk1.top() > nums2[i]) {
                stk1.pop();
                k--;
            }
            stk1.push(nums2[i]);
        }
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (k && stk2.size() && stk2.top() > nums2[i]) {
                stk1.pop();
                k--;
            }
            stk2.push(nums2[i]);
        }
        for (int i = nums1.size() - 1; i >= 0; i--) {
            while (k && stk2.size() && stk2.top() > nums1[i]) {
                stk2.pop();
                k--;
            }
            stk2.push(nums1[i]);
        }
        
        bool flag = false;
        while (stk2.size()) {
            if (stk2.top() < stk1.top()) {
                flag = true;
                break;
            }
            stk1.pop();
            stk2.pop();
        }
        vector<int> res;
        if (flag) {
            while (stk1.size()) {
                res.push_back(stk1.top());
                stk1.pop();
            }
        } else {
            while (stk2.size()) {
                res.push_back(stk2.top());
                stk2.pop();
            }
        }
        return res;
    }
};