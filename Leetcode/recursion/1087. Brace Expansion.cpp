//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    vector <vector<string>> a;
    string ans;
    vector <string> res;

    void build(int i) {
        if (i == a.size()) {
            res.push_back(ans);
            return;
        }
        for (int j = 0; j < a[i].size(); j++) {
            string temp = ans;
            ans = ans + a[i][j];
            build(i + 1);
            ans = temp;
        }
    }

    vector <string> expand(string S) {
        int n = S.size();
        int i = 0;

        while (i < n) {
            if ((i == 0 && S[i] != '{') ||
                (i > 0 && S[i] != '{' && S[i - 1] == '}')) {
                string s = string(1, S[i]);
                int j = i;
                while (j + 1 < n && S[j + 1] != '}' && S[j + 1] != '{') {
                    j++;
                    s += S[j];
                }
                a.push_back({s});
                i = j + 1;
            } else if (S[i] == '{') {
                i++;
                vector <string> s;
                int j;
                for (j = i; j < n; j += 2) {
                    s.push_back(string(1, S[j]));
                    if (S[j + 1] == '}') break;
                }
                a.push_back(s);
                i = j + 2;
            }
        }
        ans = "";
        build(0);
        sort(res.begin(), res.end());
        return res;
    }
};
