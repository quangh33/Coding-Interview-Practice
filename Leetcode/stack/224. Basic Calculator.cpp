//
// Created by Hoang, Quang on 2019-08-14.
//

// https://leetcode.com/problems/basic-calculator/

class Solution {
public:
    void convert(string S, vector <string> &a) {
        int i = 0;
        int n = S.length();
        while (i < n) {
            if (S[i] == '+' || S[i] == '-' || S[i] == ')' || S[i] == '(') {
                a.push_back(string(1, S[i]));
                i++;
            } else if (S[i] != ' ') {
                int j = i;
                string num = string(1, S[i]);
                while (j + 1 < n && isdigit(S[j + 1])) {
                    j++;
                    num += S[j];
                }
                a.push_back(num);
                i = j + 1;
            }
        }
    }

    int calculate(string s) {
        string S = "";
        for (char c: s) if (c != ' ') S += c;
        int n = S.length();
        if (n == 0) return 0;

        vector<int> value;
        vector<int> sign;
        vector <string> a;

        convert(S, a);

        int count = 0;
        stack <pair<char, int>> st;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] == "(") {
                if (i == 0 || a[i - 1] == "+") st.push(make_pair('(', 1));
                else {
                    st.push(make_pair('(', -1));
                    count++;
                }
            } else if (a[i] == ")") {
                if (st.top().second == -1) count--;
                st.pop();
            } else if (a[i] != "+" && a[i] != "-") {
                int currentSign = 1;
                if (i > 0 && a[i - 1] == "-") currentSign = -1;
                if (count % 2 == 1) currentSign = -currentSign;
                value.push_back(stoi(a[i]));
                sign.push_back(currentSign);
            }
        }

        int res = 0;
        for (int i = 0; i < value.size(); i++) {
            res += value[i] * sign[i];
            // cout<<value[i] * sign[i]<<endl;
        }
        return res;
    }
};
