#include <bits/stdc++.h>

using namespace std;

struct Bbox {
    int x1;
    int y1;
    int x2;
    int y2;
    Bbox(int xx1, int yy1, int xx2, int yy2): x1(xx1), y1(yy1), x2(xx2), y2(yy2){}
};

float IoU(Bbox b1, Bbox b2) {
    int xx1 = max(b1.x1, b2.x1);
    int yy1 = max(b1.y1, b2.y1);
    int xx2 = min(b1.x2, b2.x2);
    int yy2 = min(b1.y2, b2.y2);

    int w = max(0, xx2 - xx1);
    int h = max(0, yy2 - yy1);
    int inter = w * h;

    int area1 = (b1.x2 - b1.x1) * (b1.y2 - b1.y1);
    int area2 = (b2.x2 - b2.x1) * (b2.y2 - b2.y1);

    float iou = (float) inter / (area1 + area2 - inter);
    return iou;
}

int func(vector<int>& nums) {
    int n = nums.size();
    int res = INT_MIN, pre = 0;
    for (int i = 0; i < n; i++) {
        int t = max(pre, 0) + nums[i];
        res = max(res, t);
        pre = t;
    }
    return res;
}

int func2(vector<int>& nums) {
    int n = nums.size();
    int res1 = INT_MIN, pre = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        int t = max(pre, 0) + nums[i];
        res1 = max(res1, t);
        pre = t;
        sum += nums[i];
    }

    int res2 = 0, pre2 = 0;
    for (int i = 0; i < n; i++) {
        int t = min(pre2, 0) + nums[i];
        res2 = min(res2, t);
        pre2 = t;
    }

    int ans = max(res1, sum - res2);
    return ans;
}


int main() {
    // Bbox b1(0, 0, 20, 20);
    // Bbox b2(0, 0, 20, 10);
    // float iou = IoU(b1, b2);
    // cout << iou << endl;

    vector<int> nums = {1, 2, -3, -4, 5, 6, -7, -8, 9};
    vector<int> nums2 = {1, 2, -3, -4, 5};
    int res = func(nums);
    int res2 = func2(nums2);
    cout << res2 << endl;
    return 0;
}
