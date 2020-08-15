#include <bits/stdc++.h>

using namespace std;

/**
 * nms的计算
 */

struct Bbox {
    int left;
    int top;
    int right;
    int bottom;
    float score;
    Bbox(int l, int t, int r, int b, float s) : left(l), top(t), right(r), bottom(b), score(s) {}
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

bool cmp(Bbox& b1, Bbox& b2) {
    return b1.score > b2.score;
}

void nms(vector<Bbox>& boxes, float thresh) {
    if (!boxes.size()) return;
    sort(boxes.begin(), boxes.end(), cmp); // 先按照置信度排序
    for (int i = 0; i < boxes.size(); i++) {
        if (boxes[i].score == 0) continue; // 如果过滤掉了就跳过
        for (int j = i + 1; j < boxes.size(); j++) {
            if (boxes[j].score == 0) continue;
            float iou = IOU(boxes[i], boxes[j]); // 计算iou
            if (iou > thresh) boxes[j].score = 0; // iou大于阈值的话，过滤掉，这里把score设置为0表示过滤掉了
        }
    }
    int idx = 0;
    // 把未过滤的框提出来。
    for (int i = 0; i < boxes.size(); i++) {
        if (boxes[i].score) {
            boxes[idx++] = boxes[i];
        }
    }
    boxes.erase(boxes.begin() + idx, boxes.end());
}

int main() {
    Bbox b1(0, 0, 80, 80, 0.91);
    Bbox b2(0, 0, 80, 85, 0.75);
    Bbox b3(0, 0, 80, 70, 0.84);
    Bbox b4(0, 0, 80, 90, 0.63);
    Bbox b5(0, 0, 50, 60, 0.78);
    Bbox b6(0, 0, 20, 30, 0.89);
    vector<Bbox> boxes = {b1 , b2, b3, b4, b5, b6};
    nms(boxes, 0.5);
    cout << boxes.size() << endl;
    for (auto it : boxes)
        cout << it.left << ' ' << it.top << ' ' << it.right << ' ' << it.bottom << ' ' << it.score << endl;
    
    return 0;
}