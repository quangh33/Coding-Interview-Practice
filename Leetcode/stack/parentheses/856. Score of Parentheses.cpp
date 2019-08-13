//
// Created by Hoang, Quang on 2019-08-13.
//

// https://leetcode.com/problems/score-of-parentheses/

class Solution {
public:
    int scoreOfParentheses(string S) {
        int n = S.length();
        int count = 0;
        int res = 0;
        int current = 0;

        for(int i = 0; i < n; i++) {
            if (count == 0) {
                res += current;
                current = 0;
            }

            if (S[i] == '(') {
                count++;
            } else {
                if (S[i] == ')') {
                    count--;
                    if (S[i-1] == '(') {
                        res+= (1<<count);
                    }
                }
            }
        }

        return res;
    }
};