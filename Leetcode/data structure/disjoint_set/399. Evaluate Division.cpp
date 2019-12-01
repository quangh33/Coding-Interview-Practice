//
// Created by Hoang, Quang on 2019-08-31.
//

// https://leetcode.com/problems/evaluate-division/

#include<iostream>
#include<vector>
#include<queue>
#include <unordered_map>
#include <cstring>
#include <set>
#include <map>

using namespace std;

unordered_map<string, int> ind;
vector<int> p;
vector<int> r;
vector<vector<pair<double, int>>> a;
vector<bool> visit;
double ans;
bool found;

int find(int i) {
    if (i == p[i]) return i;
    return find(p[i]);
}

void merge(int i, int j) {
    if (r[i] > r[j]) {
        p[j] = i;
    } else {
        p[i] = j;
        if (r[i] == r[j]) r[j]++;
    }
}

void dfs(int u, int target, double p) {
    visit[u] = true;
    if (u == target) {
        found = true;
        ans = p;
        return;
    }
    for (auto i: a[u]) {
        int v = i.second;
        double w = i.first;

        if (!visit[v]) {
            dfs(v, target, p * w);
        }
    }
}

vector<double>
calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
    int n = 0;
    for (auto e: equations) {
        string u = e[0], v = e[1];
        if (ind.count(u) == 0) ind[u] = (n++);
        if (ind.count(v) == 0) ind[v] = (n++);
    }
    a = vector<vector<pair<double, int>>>(n);
    p = vector<int>(n);
    r = vector<int>(n);

    int i = -1;
    for (int i = 0; i < n; i++) {
        p[i] = i;
        r[i] = 0;
    }

    for (auto e: equations) {
        i++;
        int u = ind[e[0]], v = ind[e[1]];

        a[u].push_back(make_pair(values[i], v));
        a[v].push_back(make_pair(1 / values[i], u));

        int u_id = find(u), v_id = find(v);
        if (u_id != v_id) {
            merge(u_id, v_id);
        }
    }

    vector<double> res;
    for (auto e: queries) {
        if (ind.count(e[0]) == 0 || ind.count(e[1]) == 0) {
            res.push_back(-1);
        } else {
            int u = ind[e[0]], v = ind[e[1]];
            if (find(u) != find(v)) {
                res.push_back(-1);
            } else {
                found = false;
                visit = vector<bool>(n, false);
                dfs(u, v, 1);
                res.push_back(ans);
            }
        }
    }
    for (auto x: res) cout << x << endl;

    return res;
}

int main() {
    vector<vector<string>> equations = {
            {"a", "b"},
            {"b", "c"},
    };

    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"x", "a"}};
    calcEquation(equations, values, queries);
    return 0;
}
