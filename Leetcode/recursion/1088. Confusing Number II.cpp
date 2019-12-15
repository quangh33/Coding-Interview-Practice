//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    int fx[10][2];
    string s;
    int res = 0;
    int n;
    long can;
    unordered_map<int, int> m;
    int d[5] = {0, 1, 6, 8, 9};
    int ma;

    bool ok(long x) {
        if (x < 1 || x > ma) return false;
        long y = 0;
        long temp = x;
        while (x) {
            int d = x % 10;
            x = x / 10;
            y = y * 10 + m[d];
        }
        return y != temp;
    }

    void build(int i) {
        if (i == n) {
            if (ok(can)) {
                // cout<<can<<endl;
                res++;
            }
            return;
        }
        for (int j = 0; j < 5; j++) {
            can = can * 10 + d[j];
            build(i + 1);
            can = can / 10;
        }
    }


    int confusingNumberII(int N) {
        ma = N;
        s = to_string(N);
        n = s.size();
        m[0] = 0;
        m[1] = 1;
        m[6] = 9;
        m[9] = 6;
        m[8] = 8;
        build(0);
        return res;
    }
};