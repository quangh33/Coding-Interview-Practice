//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    string V = "ueoai";

    bool isVowel(char c) {
        return V.find(c) != string::npos;
    }

    string removeVowels(string S) {
        string res = "";
        for (char c: S) {
            if (isVowel(c)) continue;
            res += c;
        }
        return res;
    }
};