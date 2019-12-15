//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    vector <vector<int>> insert(vector <vector<int>> &a, vector<int> &newInterval) {
        int n = a.size();
        vector <vector<int>> b;
        int i;
        for (i = 0; i < n; i++) {
            if (a[i][0] <= newInterval[0]) b.push_back(a[i]);
            else break;
        }
        b.push_back(newInterval);
        for (int j = i; j < n; j++)
            b.push_back(a[j]);

        n++;
        i = 0;
        vector <vector<int>> res;

        while (i < n) {
            int j = i;
            int end = b[i][1];
            while (j + 1 < n && b[j + 1][0] <= end) {
                j++;
                end = max(end, b[j][1]);
            }
            res.push_back({b[i][0], end});
            i = j + 1;
        }
        return res;
    }
};