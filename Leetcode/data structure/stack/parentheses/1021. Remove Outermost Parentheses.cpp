//
// Created by Hoang, Quang on 2019-08-12.
//

// https://leetcode.com/problems/remove-outermost-parentheses/

#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        int count = 0;
        int start = 0;
        string res = "";
        for(int i = 0; i < S.length(); i++) {
            if (S[i] == '(') count++;
            else count--;
            if (count == 0) {
                res+= S.substr(start+1, i-start-1);
                start = i+1;
            }
        }
        return res;
    }
};