//
// Created by Hoang, Quang on 2019-11-20.
//

class Solution {
    vector<int> s;
    int n;
    vector<vector<int>> a;
public:
    Solution(vector<vector<int>>& rects) {
        a = rects;
        n = rects.size();
        s = vector<int>();
        for(auto rect: rects) {
            s.push_back((rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1));
        }

        for(int i = 1; i < n; i++) {
            s[i] = s[i-1] + s[i];
        }
    }

    vector<int> pick() {
        int r = rand() % s[n-1];
        int i = upper_bound(s.begin(), s.end(), r) - s.begin();

        int x = a[i][0] + rand() % (a[i][2] - a[i][0] + 1);
        int y = a[i][1] + rand() % (a[i][3] - a[i][1] + 1);
        return { x, y };
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */