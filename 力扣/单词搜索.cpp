#include <string>
#include <vector>

using namespace std;

/**
 * 题目79：单词搜索
 */
class LeeCode79 {
   public:
    /**
     * 思路：回溯法
     */
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) {
            return false;
        }
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        // 依次将数组中的每一个位置当作起始点，查找
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    if (DFS2(board, i, j, 0, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

   private:
    /**
     * 提交超时，需要优化
     * 空间复杂度：O(MN)
     */
    bool DFS(vector<vector<char>> board, int x, int y, int index, string word,
             vector<vector<bool>>& visited) {
        // 找到了返回true
        if (index == word.size()) {
            return true;
        }
        int rows = board.size();
        int cols = board[0].size();
        // 没找到的情况
        if (x < 0 || x >= rows || y < 0 || y >= cols ||
            board[x][y] != word[index] || visited[x][y] == true) {
            return false;
        }
        // 当前字符符合要求，标记访问过了
        visited[x][y] = true;
        // 继续上下左右找下一个字符是否符合
        if (DFS(board, x - 1, y, index + 1, word, visited) ||
            DFS(board, x, y - 1, index + 1, word, visited) ||
            DFS(board, x + 1, y, index + 1, word, visited) ||
            DFS(board, x, y + 1, index + 1, word, visited)) {
            return true;
        }
        // 否则将当前字符标记为未访问
        visited[x][y] = false;
        return false;
    }

    /**
     * 空间复杂度：O(1)
     * 利用数组本身来标记！！！ 设计太巧妙了！！！
     */
    bool DFS2(vector<vector<char>> board, int x, int y, int index,
              string word) {
        // 注意这儿的判断
        if (index == word.size() - 1) {
            return true;
        }
        int rows = board.size();
        int cols = board[0].size();
        char temp = board[x][y];
        board[x][y] = '\n';  // 标记当前字符已经被访问
        // 四个方向寻找
        if (x + 1 < rows && board[x + 1][y] == word[index + 1]) {
            if (DFS2(board, x + 1, y, index + 1, word)) {
                return true;
            }
        }
        if (x - 1 >= 0 && board[x - 1][y] == word[index + 1]) {
            if (DFS2(board, x - 1, y, index + 1, word)) {
                return true;
            }
        }
        if (y + 1 < cols && board[x][y + 1] == word[index + 1]) {
            if (DFS2(board, x, y + 1, index + 1, word)) {
                return true;
            }
        }
        if (y - 1 >= 0 && board[x][y - 1] == word[index + 1]) {
            if (DFS2(board, x, y - 1, index + 1, word)) {
                return true;
            }
        }
        // 回溯，如果前面没有返回，说明以当前字符出发找不到，就将当前字符复原
        board[x][y] = temp;
        return false;
    }
};