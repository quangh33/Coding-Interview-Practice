//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    string addBoldTag(string s, vector <string> &dict) {
        int n = s.size();
        int fx[n];
        int m = dict.size();
        bool open[n], close[n];

        memset(open, false, sizeof(open));
        memset(close, false, sizeof(close));

        for (int i = 0; i < n; i++) {
            fx[i] = 0;
            for (int j = 0; j < m; j++) {
                string t = s.substr(i, dict[j].length());
                if (t == dict[j])
                    fx[i] = max(fx[i], (int) dict[j].length());
            }
        }

        int i = 0;
        while (i < n) {
            int end = i;
            if (fx[i] != 0) {
                for (int j = i; j <= min(n - 1, end + 1); j++) {
                    if (fx[j] != 0) end = max(end, j + fx[j] - 1);
                }
                open[i] = true;
                close[end] = true;
                i = end + 1;
            } else i++;
        }

        string res = "";
        for (int i = 0; i < n; i++) {
            if (open[i] && close[i]) {
                res = res + "<b>" + s[i] + "</b>";
            } else if (open[i] || close[i]) {
                if (open[i]) res = res + "<b>" + s[i];
                if (close[i]) res = res + s[i] + "</b>";
            } else {
                res = res + s[i];
            }
        }

        return res;
    }
};