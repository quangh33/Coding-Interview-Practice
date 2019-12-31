//
// Created by Hoang, Quang on 2019-08-30.
//

class Solution {
public:
    vector<string> res;
    string s;

    void build(int i, int sum, int n) {
        if (i == n) {
            if (sum == 0) {
                res.push_back(s);
            }
            return;
        }
        if (sum < 0) return;
        if (sum > n - i) return;
        string temp = s;
        s = temp + "(";
        build(i + 1, sum + 1, n);
        s = temp + ")";
        build(i + 1, sum - 1, n);
        s = temp;
    }
    vector<string> generateParenthesis(int n) {
        s = "";
        build(0, 0, n * 2);
        return res;
    }
};
