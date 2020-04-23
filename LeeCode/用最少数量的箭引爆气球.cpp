#include <vector>

using namespace std;

/**
 * 题目452：用最少数量的箭引爆气球
 */
class LeeCode452 {
   public:
    bool static compare(vector<int> v1, vector<int> v2) {
        return v1[1] < v2[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) {
            return 0;
        }
        sort(points.begin(), points.end(), compare);

        int count = 0;
        int x_end = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > x_end) {
                count++;
                x_end = points[i][1];
            }
        }
        return count;
    }
};