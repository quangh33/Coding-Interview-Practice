//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    vector <string> generatePossibleNextMoves(string s) {
        vector <string> res;
        if (s.size() == 0) return res;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == '+' && s[i + 1] == '+') {
                string t = s;
                res.push_back(t.replace(t.begin() + i, t.begin() + i + 2, "--"));
            }
        }
        return res;
    }
};