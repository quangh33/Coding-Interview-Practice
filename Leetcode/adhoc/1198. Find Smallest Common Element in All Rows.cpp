//
// Created by Hoang, Quang on 2019-11-21.
//

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& a) {
        int n = a.size();
        unordered_map<int, int> m[n];
        for(int i = 0; i < n; i++)
            for(int x: a[i]) m[i][x]++;

        for(int i = 0; i < a[0].size(); i++) {
            bool ok = true;
            int x = a[0][i];
            for(int j = 1; j < n; j++)
                if (m[j].count(x) == 0) {
                    ok = false;
                    break;
                }
            if (ok) return x;
        }
        return -1;
    }
};
