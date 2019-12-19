//
// Created by Hoang, Quang on 2019-12-19.
//

class Solution {
public:
    typedef pair<int, int> ii;
    typedef pair<int, ii> iii;

    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        priority_queue<iii, vector<iii>, greater<iii>> q;
        int n = a.size();
        int m = b.size();
        int count = 0;
        for(int i = 0; i < n; i++)
            if (m > 0) q.push(iii(a[i] + b[0], ii(i, 0)));
        vector<vector<int>> res;
        while (!q.empty()) {
            if (count == k) break;
            count++;
            int i = q.top().second.first;
            int j = q.top().second.second;
            q.pop();
            res.push_back({ a[i], b[j] });
            if (j + 1 < m) {
                q.push(iii(a[i] + b[j+1], ii(i, j+1)));
            }
        }
        return res;
    }
};