//
// Created by Hoang, Quang on 2019-08-23.
//

// https://leetcode.com/problems/letter-case-permutation/

class Solution {
public:
    vector<string> res;
    vector<bool> pos;

    void build(int i, string S) {
        int n = S.size();
        if (i == n) {
            string s = "";
            for(int j = 0; j < pos.size(); j++)
                if (pos[j]) s = s + char(tolower(S[j]));
                else s = s + char(toupper(S[j]));
            res.push_back(s);
            return;
        }
        if (isalpha(S[i])) {
            pos[i] = true;
            build(i+1, S);
        }
        pos[i] = false;
        build(i+1, S);
    }

    vector<string> letterCasePermutation(string S) {
        pos = vector<bool>(S.size(), false);
        build(0, S);
        return res;
    }
};
