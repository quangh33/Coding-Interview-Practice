//
// Created by Hoang, Quang on 2019-08-12.
//

// https://leetcode.com/problems/sliding-puzzle/

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    bool withinBoundary(int u, int v, int n, int m) {
        return (u >= 0 && u < n && v >= 0 && v < m);
    }

    int hash(vector<vector<int>> board) {
        return
                board[0][0] * 1+
                board[0][1] * 6 +
                board[0][2] * 6*6 +
                board[1][0] * 6*6*6 +
                board[1][1] * 6*6*6*6 +
                board[1][2] * 6*6*6*6*6;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        queue<vector<vector<int>>> q;
        q.push(board);

        int dis[50000];
        memset(dis, -1, sizeof(dis));

        vector<vector<int>> target;
        vector<int> row1 = { 1, 2, 3 };
        vector<int> row2 = { 4, 5, 0 };

        target.push_back(row1);
        target.push_back(row2);
        int hashTarget = hash(target);

        dis[hash(board)] = 0;


        while (!q.empty()) {
            vector<vector<int>> u = q.front();
            int hashU = hash(u);
            q.pop();

            int zeroX, zeroY;

            for(int i = 0; i < 2; i++)
                for(int j = 0; j < 3; j++) {
                    if (u[i][j] == 0) {
                        zeroX = i;
                        zeroY = j;
                        break;
                    }
                }

            for(int k = 0; k < 4; k++) {
                vector<vector<int>> v = u;
                int i = zeroX + dx[k];
                int j = zeroY + dy[k];
                if (withinBoundary(i,j,2,3)) {
                    swap(v[zeroX][zeroY], v[i][j]);
                    int hashV = hash(v);
                    if (dis[hashV] == -1) {
                        dis[hashV] = dis[hashU] + 1;
                        q.push(v);
                        if (hashV == hashTarget) return dis[hashV];
                    }
                }
            }
        }
        return dis[hashTarget];
    }
};

