#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    char c;
    int num;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }

    // string s;
    // getline(cin, s);
    // cout << s << endl;

    return 0;
}