//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    vector <vector<int>> multiply(vector <vector<int>> &A, vector <vector<int>> &B) {
        int n = A.size();
        int m = A[0].size();
        int p = B[0].size();

        vector <vector<int>> res = vector < vector < int >> (n, vector<int>(p, 0));
        for (int i = 0; i < n; i++)
            for (int k = 0; k < m; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < p; j++) res[i][j] += A[i][k] * B[k][j];
            }
        return res;
    }
};
