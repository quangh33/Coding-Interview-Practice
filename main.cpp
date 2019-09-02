#include<iostream>
#include<vector>
#include<queue>
#include <unordered_map>
#include <cstring>
#include <set>
#include <map>

using namespace std;

typedef pair<int, int> ii;

void dfs(int u, vector<vector<int>> rooms, vector<bool>& visit) {
    visit[u] = true;
    for(int v: rooms[u])
        if (!visit[v]) dfs(v, rooms, visit);
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    vector<bool> visit = vector<bool>(rooms.size(), false);
    int count = 0;
    for(int i = 0; i < rooms.size(); i++) {
        if (!visit[i]) dfs(i, rooms, visit);
        count++;
        if (count == 2) return false;
    }
    return true;
}

int main() {
    int a[4];
    memset(a, -1, sizeof(a));
    cout<<a[0];
    return 0;
}