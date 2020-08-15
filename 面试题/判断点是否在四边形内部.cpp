#include <bits/stdc++.h>

using namespace std;

/**
 * 判断点是否在四边形内部
 */

/**
 * 方法一：如果一个点在这个凸四边形内，那么按照顺时针方向，该点一定在每条边的右侧。可使用矢量叉积来看：该方法只适用于凸多边形。
 * 叉积的一个非常重要性质是可以通过它的符号判断两矢量相互之间的顺逆时针关系：
 * 若 P × Q > 0 , 则P在Q的顺时针方向。
 * 若 P × Q < 0 , 则P在Q的逆时针方向。
 * 若 P × Q = 0 , 则P与Q共线，但可能同向也可能反向。
 * AB × AM>0；
 * BC × BM>0； 
 * CD × CM>0； 
 * DA × DM>0
 * 
 * 方法二：  假设该凸四边形为ABCD，待判断的点为M，过点M任做一条射线L（起点为M，终点无穷远）。
 * 如果M在凸四边形内部，则直线L必与四边形相交，且有一个交点。如果M不在凸四边形内部，
 * 则L可与四边形相交也可能不相交，相交的情况有两种，一个交点（过四边形的顶点），或者两个交点。
 * 过点M任做一条射线L，判断交点个数，奇数个则M点在内部，反之在外部。这个适用于多边形以及凹多边形。
 * 
 * 方法三：如果M在ABCD内部，则ABCD任意一点和M所构成的向量在改点所在边的中间，即叉积的乘积<0，则：
 * AB × AM  * AM × AD<0；
 * BC × BM  * BM × BA<0；
 * CD × CM * CM × CB<0；
 * DA × DM * DM × DC<0
 * 
 * 方法四：点M若在ABCD内部，则M与ABCD任意二点构成的三角形面积之和等于ABCD的面积，否则大于ABCD的面积。
 * https://blog.csdn.net/baidu_38172402/article/details/88718170
 */

class Solution {
    public:
    typedef pair<int, int> PII;
    /**
     * 方法一的实现
     */
    bool isPointInRect(vector<PII>& rect, int x, int y) {
        auto A = rect[0], B = rect[1], C = rect[2], D = rect[3];
        int abAm = (B.first - A.first) * (y - A.second) - (B.second - A.second) * (x - A.first);
        int bcBm = (C.first - B.first) * (y - B.second) - (C.second - B.second) * (x - B.first);
        int cdCm = (D.first - C.first) * (y - C.second) - (D.second - C.second) * (x - C.first);
        int daDm = (A.first - D.first) * (y - D.second) - (A.second - D.second) * (x - D.first);
        if ((abAm > 0 && bcBm > 0 && cdCm > 0 && daDm > 0) || (abAm < 0 && bcBm < 0 && cdCm < 0 && daDm < 0))
            return true;
        return false;
    }
};

int main() {
    
    vector<pair<int, int>> nums = {{0,0}, {3, 0}, {3, 4}, {0, 4}};
    Solution s = Solution();
    bool res = s.isPointInRect(nums, 1, 5);
    cout << res << endl;

    return 0;
}