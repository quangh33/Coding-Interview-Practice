//
// Created by Hoang, Quang on 2019-11-22.
//

class Solution {
public:
    int cal(vector<int> a, vector<int> b) {
        int n = a.size();
        int fx[n], gx[n];
        fx[0] = 1;
        gx[0] = 0;

        for (int i = 1; i < n; i++) {
            fx[i] = n + 1;
            if (b[i] == a[i - 1]) fx[i] = min(fx[i], gx[i - 1] + 1);
            if (b[i] == b[i - 1]) fx[i] = min(fx[i], fx[i - 1] + 1);
            gx[i] = n + 1;
            if (a[i] == a[i - 1]) gx[i] = min(gx[i], gx[i - 1]);
            if (a[i] == b[i - 1]) gx[i] = min(gx[i], fx[i - 1]);
        }
        return min(fx[n - 1], gx[n - 1]);
    }

    int minDominoRotations(vector<int> &A, vector<int> &B) {
        int a = cal(A, B);
        int b = cal(B, A);
        int n = A.size();
        if (a > n && b > n) return -1;
        return min(a, b);
    }
};