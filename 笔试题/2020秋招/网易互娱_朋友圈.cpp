#include <bits/stdc++.h>

using namespace std;

vector<int> p;


int find(int x) {
    if (x == p[x]) return x;
    p[x] = find(p[x]);
    return p[x];
}

int count(vector<string>& filenames, vector<vector<string>>& relation) {
    int n = filenames.size();
    unordered_map<string, int> hash;
    for (int i = 0; i < n; i++) hash[filenames[i]] = i;
    p = vector<int>(n);
    for (int i = 0; i < n; i++) p[i] = i;  // 初始化
    for (auto r : relation){
        int a = hash[r[0]], b = hash[r[1]];
        p[find(a)] = find(b);
    }
    unordered_set<int> st;
    for (int i = 0; i < n; i++) st.insert(find(i));
    return st.size();
}

int main() {
    vector<string> ns = {"fileA","fileB","fileC","fileD","fileE"};
    vector<vector<string>> r = {{"fileA","fileB"},{"fileB","fileC"},{"fileD","fileE"}};
    int res = count(ns, r);
    cout<< res << endl;
    return 0;
}