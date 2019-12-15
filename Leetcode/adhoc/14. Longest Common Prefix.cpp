//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    string longestCommonPrefix(vector <string> &strs) {
        string res = "";
        int n = strs.size();
        if (n == 0) return "";
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            bool common = true;
            for (int j = 1; j < n; j++) {
                if (strs[j].length() <= i) return res;
                if (strs[j][i] != c) {
                    common = false;
                    break;
                }
            }
            if (common) res = res + c;
            else break;
        }
        return res;
    }
};