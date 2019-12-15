//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    bool isStrobogrammatic(string s) {
        unordered_map<char, char> m;
        m['0'] = '0';
        m['1'] = '1';
        m['2'] = 'x';
        m['3'] = 'x';
        m['4'] = 'x';
        m['5'] = 'x';
        m['6'] = '9';
        m['7'] = 'x';
        m['8'] = '8';
        m['9'] = '6';
        string t = "";
        for (char c: s)
            t = t + m[c];
        reverse(t.begin(), t.end());
        return t == s;
    }
};