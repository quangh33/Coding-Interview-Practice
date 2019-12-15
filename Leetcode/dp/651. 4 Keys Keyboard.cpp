//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    int maxA(int N) {
        int fx[N + 1];
        fx[1] = 1;
        for (int i = 2; i <= N; i++) {
            fx[i] = fx[i - 1] + 1;
            for (int j = 1; j < i; j++)
                fx[i] = max(fx[i], fx[j] * (i - j - 1));
        }
        return fx[N];
    }
};