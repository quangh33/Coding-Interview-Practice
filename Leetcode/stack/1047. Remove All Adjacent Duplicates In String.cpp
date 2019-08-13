//
// Created by Hoang, Quang on 2019-08-13.
//

// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> s;
        string res = "";
        if (S.length() == 0) return res;
        for(int i = 0; i < S.length(); i++) {
            if (s.empty() || S[i] != s.top()) s.push(S[i]); else s.pop();
        }
        while (!s.empty()) {
            res = s.top() + res;
            s.pop();
        }
        return res;
    }
};

