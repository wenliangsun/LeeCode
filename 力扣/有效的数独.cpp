#include <map>
#include <vector>

using namespace std;

/**
 * 题目36：有效的数独
 */
class LeeCode36 {
   public:
    /**
     * 思路：利用hashmap(如果考虑出现次数之类的可优先考虑hashmap)
     * 每一行，每一列，每一个字块都是一个hashmap
     */
    bool isValidSudoku(vector<vector<char>>& board) {
        // 行哈希表
        vector<map<int, int>> rows(9, map<int, int>());
        // 列哈希表
        vector<map<int, int>> cols(9, map<int, int>());
        // 块哈希表
        vector<map<int, int>> blocks(9, map<int, int>());
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    // 块的索引
                    int block_index = (i / 3) * 3 + j / 3;
                    // 统计各个哈希表中数字出现的次数
                    rows[i][num] = rows[i].count(num) ? rows[i][num] + 1 : 1;
                    cols[j][num] = cols[j].count(num) ? cols[j][num] + 1 : 1;
                    blocks[block_index][num] =
                        blocks[block_index].count(num)
                            ? blocks[block_index][num] + 1
                            : 1;
                    // 如果某一个哈希表中数字出现的次数大于1，则返回false
                    if (rows[i][num] > 1 || cols[j][num] > 1 ||
                        blocks[block_index][num] > 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};