//
// Created by Hoang, Quang on 2019-08-13.
//

// https://leetcode.com/problems/baseball-game/

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int res = 0;
        int n = ops.size();
        int point;
        int top = 0;
        int st[1001];

        for(string s: ops) {
            if (s == "D") {
                if (top != -1) {
                    point = st[top] * 2;
                    st[++top] = point;
                }
            } else if (s == "+") {
                point = 0;
                if (top >= 1) point = st[top] + st[top-1];
                else point = st[top];
                st[++top] = point;
            } else if (s == "C") {
                if (top != -1) {
                    top--;
                }
            } else {
                st[++top] = stoi(s);
            }
        }
        for(int i = 0; i <= top; i++) res+=st[i];
        return res;
    }
};
