//
// Created by Hoang, Quang on 2019-09-02.
//

// https://leetcode.com/problems/flower-planting-with-no-adjacent/

class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> a[N+1];
        for(auto path: paths) {
            int u = path[0] - 1;
            int v = path[1] - 1;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        vector<int> res = vector<int>(N);
        for(int i = 0; i < N; i++) {
            bool color[5];
            memset(color, false, sizeof(color));
            for(int j: a[i])
                color[res[j]] = true;

            for(int j = 1; j < 5; j++)
                if (!color[j]) {
                    res[i] = j;
                    break;
                }
        }
        return res;
    }
};