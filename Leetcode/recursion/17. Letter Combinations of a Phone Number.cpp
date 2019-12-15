//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    vector<string> res;
    string com;
    int n;
    string tel[10];

    void build(int i, string digits) {
        if (i == n) {
            res.push_back(com);
            return;
        }
        string temp = com;
        for(int j = 0; j < 4; j++)
            if (tel[digits[i] - '0'].size() > j) {
                com = com + tel[digits[i] - '0'][j];
                build(i+1, digits);
                com = temp;
            }
    }

    vector<string> letterCombinations(string digits) {
        n = digits.size();
        if (n == 0) return {};
        tel[2] = "abc";
        tel[3] = "def";
        tel[4] = "ghi";
        tel[5] = "jkl";
        tel[6] = "mno";
        tel[7] = "pqrs";
        tel[8] = "tuv";
        tel[9] = "wxyz";
        com = "";

        build(0, digits);
        return res;
    }
};