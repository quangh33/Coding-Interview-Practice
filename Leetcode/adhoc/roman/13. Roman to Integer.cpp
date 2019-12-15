//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        for(int i = 0; i < s.size(); i++) {
            int cur = m[s[i]];
            int next = i == s.size() - 1 ? INT_MIN : m[s[i+1]];
            if (cur < next) res -= cur;
            else res += cur;
        }
        return res;
    }
};
