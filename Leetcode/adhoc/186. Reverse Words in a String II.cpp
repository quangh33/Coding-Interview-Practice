//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    void reverseWords(vector<char> &s) {
        s.push_back(' ');
        string t = "";
        vector <string> a;
        for (char c: s) {
            if (c == ' ') {
                a.push_back(t);
                t = "";
            } else t = t + c;
        }
        vector<char> res;
        for (int i = a.size() - 1; i >= 0; i--) {
            for (char c: a[i])
                res.push_back(c);
            res.push_back(' ');
        }
        res.pop_back();
        s = res;
    }
};