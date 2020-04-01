#include <vector>

using namespace std;

/**
 * 题目11:盛最多水的容器
 * 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
 * 在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 *
 */
class LeeCode11 {
   public:
    int maxArea(vector<int>& height) {
        int p1 = 0;
        int p2 = height.size() - 1;
        int maxarea = 0;
        while (p1 < p2) {
            int minnum = height[p1] < height[p2] ? height[p1] : height[p2];
            int area = minnum * (p2 - p1);
            cout << area << endl;
            if (area > maxarea) {
                maxarea = area;
            }
            if (height[p1] < height[p2]) {
                p1++;
            } else {
                p2--;
            }
        }
        return maxarea;
    }
};