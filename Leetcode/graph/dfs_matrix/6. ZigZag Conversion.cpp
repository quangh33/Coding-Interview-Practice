//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    string convert(string s, int row) {
        int n = s.size();
        if (row == 1) return s;
        int col = (n - 1) / 2 + 1;
        char a[row][col];
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) a[i][j] = 0;

        int i = -1, j = 0;
        int d = 1;
        for (int k = 0; k < n; k++) {
            if (d == 1) i++;
            else {
                i--;
                j++;
            }

            a[i][j] = s[k];
            if (d == 1 && i == row - 1) d = 0;
            if (d == 0 && i == 0) d = 1;
        }

        string res = "";
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (a[i][j] != 0) {
                    res = res + a[i][j];
                }


        return res;
    }
};