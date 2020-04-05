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
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int oriColor = image[sr][sc];
        fill(image, sr, sc, oriColor, newColor);
        return image;
    }

   private:
    void fill(vector<vector<int>>& image, int x, int y, int oriColor,
              int newColor) {
        int rows = image.size();
        int cols = image[0].size();
        // 边界情况
        if (x < 0 || y < 0 || x >= rows || y >= cols) {
            return;
        }
        // 不需要染色情况
        if (image[x][y] != oriColor) {
            return;
        }
        // 已经染过了
        if (image[x][y] == -1) {
            return;
        }
        // 标记
        image[x][y] = -1;
        fill(image, x - 1, y, oriColor, newColor);
        fill(image, x, y - 1, oriColor, newColor);
        fill(image, x + 1, y, oriColor, newColor);
        fill(image, x, y + 1, oriColor, newColor);
        // 将标记换成新的颜色
        image[x][y] = newColor;
    }
};

int main() {
    LeeCode733 code = LeeCode733();
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    vector<vector<int>> res = code.floodFill(image, 1, 1, 2);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}