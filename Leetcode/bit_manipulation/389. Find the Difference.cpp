//
// Created by Hoang, Quang on 2019-08-26.
//

class Solution {
public:
    char findTheDifference(string s, string t) {
        int res = 0;
        for(char c: s) res^= int(c);
        for(char c: t) res^= int(c);
        return char(res);
    }
};