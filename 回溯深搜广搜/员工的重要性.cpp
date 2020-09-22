#include <bits/stdc++.h>

using namespace std;

/**
 * 题目690：员工的重要性
 */

class Employee {
   public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
   public:
    int getImportance(vector<Employee*> employees, int id) {
        int res = 0;
        for (int i = 0; i < employees.size(); i++) {
            if (employees[i]->id == id) {
                res += employees[i]->importance;
                for (auto nid : employees[i]->subordinates) {
                    res += getImportance(employees, nid);
                }
            }
        }
        return res;
    }
};