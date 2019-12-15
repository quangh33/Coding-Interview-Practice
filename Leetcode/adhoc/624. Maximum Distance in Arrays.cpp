//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    int maxDistance(vector <vector<int>> &a) {
        int res = 0, mi = a[0][0], ma = a[0][a[0].size() - 1];
        for (int i = 1; i < a.size(); i++) {
            res = max(res, max(ma - a[i][0], a[i][a[i].size() - 1] - mi));
            mi = min(mi, a[i][0]);
            ma = max(ma, a[i][a[i].size() - 1]);
        }
        return res;
    }
};