//
// Created by Hoang, Quang on 2019-12-19.
//

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(') st.push(i);
            else if (c == ')') {
                if (!st.empty() && s[st.top()] == '(') st.pop();
                else st.push(i);
            }
        }

        while (!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }

        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};