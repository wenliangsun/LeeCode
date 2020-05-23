#include <vector>

using namespace std;

/**
 * 题目37：解数独
 */
class LeeCode37 {
   public:
    /**
     * 思路：回溯法
     */
    void solveSudoku(vector<vector<char>>& board) { dfs(board, 0, 0); }

   private:
    bool isValid(vector<vector<char>>& b, int r, int c, char v) {
        for (int i = 0; i < 9; i++) {
            if (b[r][i] == v) return false;
            if (b[i][c] == v) return false;
            if (b[(r / 3) * 3 + i / 3][(c / 3) * 3 + i % 3] == v) return false;
        }
        return true;
    }

    bool dfs(vector<vector<char>>& b, int x, int y) {
        int n = 9, m = 9;
        if (y == m) return dfs(b, x + 1, 0);
        if (x == n) return true;
        if (b[x][y] != '.') return dfs(b, x, y + 1);
        for (char i = '1'; i <= '9'; i++) {
            if (isValid(b, x, y, i)) {
                b[x][y] = i;
                if (dfs(b, x, y + 1)) return true;
                b[x][y] = '.';
            }
        }
        return false;
    }
};