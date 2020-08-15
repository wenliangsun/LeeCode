#include <bits/stdc++.h>

using namespace std;

/**
 * IoU的计算
 */

struct Bbox {
    int left; // x1
    int top; // y1
    int right; // x2
    int bottom; // y2
    Bbox(int l, int t, int r, int b) : left(l), top(t), right(r), bottom(b) {}
};

float IOU(Bbox b1, Bbox b2) {
    int xx1 = max(b1.left, b2.left); //交叠的区域的x1
    int xx2 = min(b1.right, b2.right); // 交叠区域的y1
    int yy1 = max(b1.top, b2.top); //交叠区域的x2
    int yy2 = min(b1.bottom, b2.bottom); // 交叠区域的y2
    int w = max(0, xx2 - xx1); // 交叠区域的宽
    int h = max(0, yy2 - yy1); // 交叠区域的高
    int inter = w * h; // 交叠区域的面积
    int area1 = (b1.right - b1.left) * (b1.bottom - b1.top); // 第一个bbox的面积
    int area2 = (b2.right - b2.left) * (b2.bottom - b2.top); // 第二个Bbox的面积
    return (float) inter / (area1 + area2 - inter); // 计算iou
}

int main() {
    Bbox b1(0, 0, 80, 30);
    Bbox b2(30, 10, 40, 25);
    float res = IOU(b1, b2);
    cout << res << endl;
    return 0;
}