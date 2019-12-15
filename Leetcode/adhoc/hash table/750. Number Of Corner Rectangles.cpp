//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    int countCornerRectangles(vector <vector<int>> &a) {
        int n = a.size();
        if (n == 0) return 0;
        int m = a[0].size();
        if (m == 0) return 0;

        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int count = 0;
                for (int k = 0; k < m; k++) {
                    if (a[i][k] == 1 && a[j][k] == 1) {
                        res = res + count;
                        count++;
                    }
                }
            }
        }

        return res;
    }
};