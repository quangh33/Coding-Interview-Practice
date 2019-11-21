//
// Created by Hoang, Quang on 2019-11-21.
//

class Solution {
public:
    int fn(string s) {
        char minChar = s[0];
        map<char, int> count;
        for(char c: s) {
            minChar = min(minChar, c);
            count[c]++;
        }
        return count[minChar];
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> fx;
        for(auto s: words)
            fx.push_back(fn(s));

        vector<int> res;
        for(auto s: queries) {
            int x = fn(s);
            int count = 0;
            for(int i: fx)
                if (x < i) count++;

            res.push_back(count);
        }
        return res;
    }
};