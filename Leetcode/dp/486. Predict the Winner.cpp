//
// Created by Hoang, Quang on 2019-09-01.
//

class Solution {
public:
    bool PredictTheWinner(vector<int>& a) {
        int n = a.size();
        int fx[n][n];
        int sum = 0;
        for(int i = 0; i < n; i++) {
            fx[i][i] = a[i];
            sum+=a[i];
        }
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                fx[i][j] = max(a[i] - fx[i+1][j], a[j] - fx[i][j-1]);
            }
        }
        cout<<fx[0][n-1];
        return (fx[0][n-1] >= 0);
    }
};