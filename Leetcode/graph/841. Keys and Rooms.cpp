//
// Created by Hoang, Quang on 2019-09-02.
//

// https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:

    void dfs(int u, vector<vector<int>> rooms, vector<bool>& visit) {
        visit[u] = true;
        for(int v: rooms[u])
            if (!visit[v]) dfs(v, rooms, visit);
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visit = vector<bool>(rooms.size(), false);
        int count = 0;
        for(int i = 0; i < rooms.size(); i++) {
            if (!visit[i]) {
                dfs(i, rooms, visit);
                count++;
                if (count == 2) return false;
            }
        }
        return true;
    }
};