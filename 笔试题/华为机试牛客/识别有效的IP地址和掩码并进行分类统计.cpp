#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * https://www.nowcoder.com/practice/de538edd6f7e4bc3a5689723a7435682?tpId=37&tqId=21241&rp=0&ru=/ta/huawei&qru=/ta/huawei/question-ranking
 */

/**
 * 判断掩码是否合法
 */
bool isValidMask(vector<int> svec) {
    bool zero = false;
    if (svec.size() != 4) {
        return false;
    }
    for (int i = 0; i < 4; i++) {
        if (zero == false) {
            if (svec[i] != 255) {
                if (svec[i] != 0 && svec[i] != 128 && svec[i] != 192 &&
                    svec[i] != 224 && svec[i] != 240 && svec[i] != 248 &&
                    svec[i] != 252 && svec[i] != 254) {
                    return false;
                } else {
                    zero = true;
                }
            }
        } else {
            if (svec[i] != 0) {
                return false;
            }
        }
    }
    if (svec[3] == 255) {
        return false;
    }
    return true;
}

vector<int> split(string s) {
    vector<int> res;
    s += '.';
    int pos = s.find('.');
    while (pos != s.npos) {
        string temp = s.substr(0, pos);
        s = s.substr(pos + 1);
        pos = s.find('.');
        if (temp.size() > 0) {
            res.push_back(stoi(temp));
        }
    }
    return res;
}

bool isValidIP(vector<int> ips) {
    if (ips.size() != 4) {
        return false;
    }
    return true;
}

int main() {
    string s;
    int cntA = 0, cntB = 0, cntC = 0, cntD = 0, cntE = 0, cntErr = 0,
        cntPri = 0;
    while (getline(cin, s)) {
        string ip = s.substr(0, s.find('~'));
        string mask = s.substr(s.find('~') + 1);

        vector<int> ips = split(ip);
        vector<int> masks = split(mask);
        if (isValidMask(masks) && isValidIP(ips)) {
            if (ips[0] >= 1 && ips[0] <= 126) {
                cntA++;
                if (ip[0] == 10) cntPri++;
            } else if (ips[0] >= 128 && ips[0] <= 191) {
                cntB++;
                if (ips[0] == 172 && (ips[1] >= 16 && ips[1] <= 31)) cntPri++;
            } else if (ips[0] >= 192 && ips[0] <= 223) {
                cntC++;
                if (ips[0] == 192 && ips[1] == 168) cntPri++;
            } else if (ips[0] >= 224 && ips[0] <= 239)
                cntD++;
            else if (ips[0] >= 240 && ips[0] <= 255)
                cntE++;
        } else
            cntErr++;
    }
    cout << cntA << ' ' << cntB << ' ' << cntC << ' ' << cntD << ' ' << cntE
         << ' ' << cntErr << ' ' << cntPri;
}