//
// Created by Hoang, Quang on 2020-01-02.
//

class Solution {
public:
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int num_wanted, int use_limit) {
        priority_queue<int> group[20010];
        vector <vector<int>> a;
        unordered_set<int> l;

        int n = values.size();

        for (int i = 0; i < n; i++) {
            group[labels[i]].push(values[i]);
            l.insert(labels[i]);
        }

        for (int i: l) {
            vector<int> g;
            while (!group[i].empty()) {
                g.push_back(group[i].top());
                group[i].pop();
            }
            a.push_back(g);
        }

        int m = l.size();
        vector<int> used = vector<int>(m, 0);

        priority_queue < pair < int, pair < int, int >> > q;
        for (int i = 0; i < m; i++) {
            q.push(make_pair(a[i][0], make_pair(i, 0)));
        }

        int count = 0;
        int res = 0;
        while (count < num_wanted && !q.empty()) {
            res += q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            used[row]++;
            count++;

            q.pop();
            if (col + 1 < a[row].size() && used[row] < use_limit) {
                col++;
                q.push(make_pair(a[row][col], make_pair(row, col)));
            }
        }
        return res;
    }
};