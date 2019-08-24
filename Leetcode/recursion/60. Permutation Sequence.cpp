//
// Created by Hoang, Quang on 2019-08-24.
//

class Solution {
public:
    string res;
    vector<int> p;
    vector<bool> used;

    void build(int i, int n, int k) {
        if (i == n) return;
        for (int j = 1; i <= n; j++) {
            if (!used[j]) {
                if (k > p[n - i - 1]) k = k - p[n - i - 1];
                else {
                    res = res + to_string(j);
                    used[j] = true;
                    build(i + 1, n, k);
                    break;
                }
            }
        }
    }

    string getPermutation(int n, int k) {
        p.push_back(1);
        int x = 1;
        for (int i = 1; i <= 9; i++) {
            x = x * i;
            p.push_back(x);
        }
        res = "";
        used = vector<bool>(n, 0);
        build(0, n, k);
        return res;
    }
};