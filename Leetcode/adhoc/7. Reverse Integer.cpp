//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        bool neg = false;
        if (s[0] == '-') {
            s.erase(s.begin());
            neg = true;
        }

        std::reverse(s.begin(), s.end());
        long long y = 0;
        for (char c: s)
            y = y * 10 + (c - '0');

        if (neg) y *= -1;

        if (y > INT_MAX || y < INT_MIN) return 0;
        return y;
        return 0;
    }
};