#include<iostream>
#include<vector>
#include<queue>
#include <unordered_map>
#include <cstring>

using namespace std;


vector<vector<int>> adj;
vector<bool> visited;
vector<bool> inDfs;

void dfs(int u, bool &canDone) {
    visited[u] = true;
    inDfs[u] = true;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            dfs(v, canDone);
        } else {
            if (inDfs[v]) {
                canDone = false;
                return;
            };
        }
    }
    inDfs[u] = false;
}

bool canFinish(int n, vector<vector<int>> &e) {
    adj = vector<vector<int>>(n);
    visited = vector<bool>(n, false);
    inDfs = vector<bool>(n, false);

    for (int i = 0; i < e.size(); i++) {
        int u = e[i][0];
        int v = e[i][1];
        adj[v].push_back(u);
    }

    bool canDone = true;
    for (int i = 0; i < n; i++)
        if (!visited[i]) {
            dfs(i, canDone);
        }

    return canDone;
}

int main() {

    vector<vector<int>> e;
    vector<int> e1 = { 3, 0 };
    vector<int> e2 = { 0, 1 };
    e.push_back(e1);
    e.push_back(e2);
    cout<<canFinish(4, e);
    return 0;
}