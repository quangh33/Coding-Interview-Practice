//
// Created by Hoang, Quang on 2019-11-21.
//

class Solution {
public:

    vector<bool> used;

    int dfs(int i, vector<vector<int>>& stones) {
        used[i] = true;
        int count = 1;
        for(int j = 0; j < stones.size(); j++)
            if (!used[j] && (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]))
                count += dfs(j, stones);

        return count;
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        used = vector<bool>(n, false);

        int res = 0;
        for(int i = 0; i < n; i++)
            if (used[i] == false) {
                res = res + dfs(i, stones) - 1;
            }

        return res;
    }
};
