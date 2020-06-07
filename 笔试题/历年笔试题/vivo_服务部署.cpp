#include <bits/stdc++.h>

using namespace std;

/*
 * Welcome to vivo !
 */

int getCountOfApp(const char* input) {
    if (NULL == input) {
        return 0;
    }
    int cnt = 0;
    for (int i = 0; input[i] != 0; ++i) {
        if (input[i] == ',') {
            ++cnt;
        }
    }
    return cnt / 2;
}

// id start from 0
int getPositionOfApp(const char* input, const int id) {
    int cntOfComma = id * 2 + 1;
    int i = 0;
    for (; input[i] != 0 && cntOfComma != 0; ++i) {
        if (input[i] == ',') {
            --cntOfComma;
        }
    }
    while (input[--i] != ' ' && input[i] != '#')
        ;
    return i + 1;
}

#define APP_MAX 1000
#define DP_MAX 2048
int disks[APP_MAX];
int mems[APP_MAX];
int users[APP_MAX];
int dp[DP_MAX][DP_MAX];

int solution(const char* input) {
    const int countOfApp = getCountOfApp(input);
    if (0 == countOfApp) {
        return 0;
    }
    int disk = 0;
    int mem = 0;

    sscanf(input, "%d %d", &disk, &mem);

    for (int i = 0; i < countOfApp; ++i) {
        const int pos = getPositionOfApp(input, i);
        sscanf(input + pos, "%d,%d,%d", &disks[i], &mems[i], &users[i]);
    }

    for (int i = 0; i < countOfApp; i++) {
        for (int j = disk; j >= disks[i]; j--) {
            for (int k = mem; k >= mems[i]; k--) {
                dp[j][k] = max(dp[j][k], dp[j - disks[i]][k - mems[i]] + users[i]);
            }
        }
    }

    return dp[disk][mem];
}

int main(int argc, char* args[]) {
    char input[10000];
    cin.getline(input, 10000);
    cout << solution(input) << endl;
}