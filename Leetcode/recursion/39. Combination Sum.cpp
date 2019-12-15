//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    vector <vector<int>> res;

    int n;
    vector<int> a;
    vector<int> x;
    // O(2 ^ (n+s)) a to the power of b
    // a/b a divided by b

    void cal(int i, int s) {
        if (i == n) {
            if (s == 0) {
                res.push_back(x);
                return;
            } else {
                return;
            }
        }

        if (a[i] <= s) {
            x.push_back(a[i]);
            cal(i, s - a[i]);
            x.pop_back();
        }
        cal(i + 1, s);
    }

    vector <vector<int>> combinationSum(vector<int> &can, int target) {
        a = can;
        n = a.size();
        cal(0, target);
        return res;
    }
};
