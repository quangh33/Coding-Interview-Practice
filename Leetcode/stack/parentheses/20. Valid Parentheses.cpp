//
// Created by Hoang, Quang on 2019-08-12.
//

#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool match(char x, char y) {
        return (x == '(' && y == ')') ||
               (x == '[' && y == ']') ||
               (x == '{' && y == '}');
    }

    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        if (n == 0) return true;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if (st.empty()) return false;
                char top = st.top();
                st.pop();
                if (!match(top, s[i])) return false;
            }
        }
        return st.empty();
    }
};