#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目733：图像渲染
 */
class LeeCode733 {
   public:
    /**
     * 思路：回溯法
     */
    int m, n;
    int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m = image.size(), n = image[0].size();
        int oldColor = image[sr][sc];
        dfs(image, sr, sc, newColor, oldColor);
        return image;
    }

   void dfs(vector<vector<int>>& image, int x, int y, int newColor, int oldColor) {
       image[x][y] = -1;
       for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < m && b >= 0 && b < n && image[a][b] == oldColor) 
                dfs(image, a, b, newColor, oldColor);
       }
       image[x][y] = newColor;
   }
};
