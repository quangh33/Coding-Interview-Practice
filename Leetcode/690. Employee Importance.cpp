//
// Created by Hoang, Quang on 2019-08-12.
//

// https://leetcode.com/problems/employee-importance/


#include <vector>
using namespace std;

// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution {
public:
    int importance[2001];
    vector<int> sub[2001];

    int dfs(int u) {
        int res = importance[u];
        for(int v: sub[u]) {
            res += dfs(v);
        }
        return res;
    }

    int getImportance(vector<Employee*> employees, int id) {
        int n = employees.size();
        if (n == 0) return 0;

        for(Employee* em: employees) {
            importance[em->id] = em->importance;
            for(int s: em->subordinates) {
                sub[em->id].push_back(s);
            }
        }
        return dfs(id);
    }
};