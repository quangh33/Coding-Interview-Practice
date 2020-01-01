//
// Created by Hoang, Quang on 2020-01-01.
//

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        if (T == 0) return 0;
        vector<pair<int, int>> a;
        for(auto clip: clips) a.push_back(make_pair(clip[0], clip[1]));
        sort(a.begin(), a.end(), [](const pair<int, int>& u, const pair<int, int>& v) {
            return (u.second < v.second || (u.second == v.second && u.first < v.first));
        });

        int n = a.size();
        if (a[n-1].second < T) return -1;
        int fx[n];
        fx[0] = a[0].first <= 0 ? 1 : INT_MAX;
        if (a[0].first <= 0 && a[0].second >= T) return 1;
        int res = INT_MAX;
        for(int i = 1; i < n; i++) {
            fx[i] = a[i].first <= 0 ? 1 : INT_MAX;
            for(int j = 0; j < i; j++) {
                if (fx[j] != INT_MAX && a[i].first <= a[j].second)
                    fx[i] = min(fx[i], fx[j] + 1);
            }
            if (a[i].second >= T) res = min(res, fx[i]);
        }

        return res == INT_MAX ? -1 : res;
    }
};