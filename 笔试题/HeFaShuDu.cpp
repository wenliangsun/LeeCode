#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Shudu {
   public:
    bool isValid(vector<string> nums) {
        vector<unordered_map<char, int>> rows(9, unordered_map<char, int>());
        vector<unordered_map<char, int>> cols(9, unordered_map<char, int>());
        vector<unordered_map<char, int>> blocks(9, unordered_map<char, int>());
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (nums[i][j] != 'X') {
                    char c = nums[i][j];
                    int block_index = (i / 3) * 3 + j / 3;
                    rows[i][c]++;
                    cols[j][c]++;
                    blocks[block_index][c]++;
                    if (rows[i][c] > 1 || cols[j][c] > 1 ||
                        blocks[block_index][c] > 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    vector<string> nums(9);
    for (int i = 0; i < 9; i++) {
        getline(cin, nums[i]);
    }
    Shudu shu = Shudu();
    bool res = shu.isValid(nums);
    if (res) {
        cout << "true";
    } else {
        cout << "false";
    }
}