#include <bits/stdc++.h>

using namespace std;

struct Bbox {
    int left;
    int top;
    int right;
    int bottom;
    float score;
    Bbox(int l, int t, int r, int b, float s): left(l), top(t), right(r), bottom(b), score(s) {}   
};

float IoU(Bbox b1, Bbox b2) {
    int xx1 = max(b1.left, b2.left);
    int yy1 = max(b1.top, b2.top);
    int xx2 = min(b1.right, b2.right);
    int yy2 = min(b1.bottom, b2.bottom);
    int w = max(0, xx2 - xx1);
    int h = max(0, yy2 - yy1);
    int inter = w * h;
    int area1 = (b1.right - b1.left) * (b1.bottom - b1.top);
    int area2 = (b2.right - b2.left) * (b2.bottom - b2.top);
    float iou = (float) inter / (area1 + area2 - inter);
    return iou;
}

bool cmp(Bbox b1, Bbox b2) {
    return b1.score > b2.score;
}

void nms(vector<Bbox>& boxes, float thresh) {
    if (boxes.empty()) return;
    sort(boxes.begin(), boxes.end(), cmp);
    for (int i = 0; i < boxes.size(); i++) {
        if (boxes[i].score == 0) continue;
        for (int j = i + 1; j < boxes.size(); j++) {
            if (boxes[j].score == 0) continue;
            float iou = IoU(boxes[i], boxes[j]);
            if (iou > thresh) boxes[j].score = 0;
        }
    }
    int idx = 0;
    for (int i = 0; i < boxes.size(); i++) {
        if (boxes[i].score) boxes[idx++] = boxes[i];
    }
    boxes.erase(boxes.begin() + idx, boxes.end());
}

int main() {
    
}