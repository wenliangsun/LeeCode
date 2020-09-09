#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

bool isConcavePolygon(vector<PII>& points) {
    int n = points.size();
    for (int i = 0; i < n; i++) {
        PII v1, v2;
        if (i == 0) {
            v1.first = points[n - 1].first - points[i].first;
            v1.second = points[n - 1].second - points[i].second;
        } else {
            v1.first = points[i - 1].first - points[i].first;
            v1.second = points[i - 1].second - points[i].second;
        }
        if (i == n - 1) {
            v2.first = points[0].first - points[i].first;
            v2.second = points[0].second - points[i].second;
        } else {
            v2.first = points[i + 1].first - points[i].first;
            v2.second = points[i + 1].second - points[i].second;
        }

        int t = v1.first * v2.second - v1.second * v2.first;
        if (t > 0) return true;
    }
    return false;
}

int main() {
    
}