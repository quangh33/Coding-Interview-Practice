//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    vector<int> assignBikes(vector <vector<int>> &workers, vector <vector<int>> &bikes) {
        int n = workers.size();
        int m = bikes.size();
        vector<int> res = vector<int>(n, -1);
        vector<bool> used = vector<bool>(m, false);
        vector <pair<int, int>> bucket[2000];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int dis = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                bucket[dis].push_back(make_pair(i, j));
            }


        for (int dis = 0; dis < 2000; dis++) {
            for (int i = 0; i < bucket[dis].size(); i++) {
                int worker = bucket[dis][i].first;
                int bike = bucket[dis][i].second;
                if (res[worker] == -1 && !used[bike]) {
                    res[worker] = bike;
                    used[bike] = true;
                }
            }
        }

        return res;
    }
};