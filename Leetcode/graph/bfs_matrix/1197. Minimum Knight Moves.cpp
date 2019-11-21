//
// Created by Hoang, Quang on 2019-11-21.
//

class Solution {
public:
    int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
    int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    typedef pair<int, int> ii;

    int within(int i, int j) {
        return i >= 0 && i <= 600 && j >= -0 && j <= 600;
    }

    int fx[601][601];

    int minKnightMoves(int x, int y) {
        queue<ii> q;
        q.push(ii(300,300));
        memset(fx, -1, sizeof(fx));

        fx[300][300] = 0;

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (i == x + 300 && j == y + 300) break;
            for(int k = 0; k < 8; k++) {
                int u = i + dx[k];
                int v = j + dy[k];
                if (within(u,v) && fx[u][v] == -1) {
                    fx[u][v] = fx[i][j] + 1;
                    q.push(ii(u, v));
                }
            }
        }

        return fx[x+300][y+300];
    }
};