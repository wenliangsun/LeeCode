#include <bits/stdc++.h>

using namespace std;

/**
 * 题目1401：圆和矩形是否有重叠
 */

class Solution {
   public:
    /**
     * 先计算矩形中心，边长；把矩形中心，圆心投影到坐标轴上；计算矩形中心与圆心在坐标轴上的距离；判断，圆心超出矩形的距离是否小于等于圆的半径;
     */
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        double rcx = (x1 + x2) / 2.0, rcy = (y1 + y2) / 2.0; // 计算矩形中心
        double dx = max((abs(rcx - x_center) - (x2 - x1) / 2.0), 0.0); // 计算dx
        double dy = max((abs(rcy - y_center) - (y2 - y1) / 2.0), 0.0); // 计算dy
        double dist = dx * dx + dy * dy; 
        return dist <= radius * radius; // 斜边小于半径时有交叠
    }
};