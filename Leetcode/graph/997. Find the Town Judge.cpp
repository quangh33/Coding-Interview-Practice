//
// Created by Hoang, Quang on 2019-09-02.
//

// https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int N, vector <vector<int>> &trust) {
        int in[N + 1];
        int out[N + 1];
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));

        for (auto pair: trust) {
            int u = pair[0];
            int v = pair[1];
            in[v]++;
            out[u]++;
        }
        for (int i = 1; i <= N; i++)
            if (in[i] == N - 1 && out[i] == 0) return i;
        return -1;
    }
};
