//
// Created by Hoang, Quang on 2019-11-21.
//

class Solution {
public:
    int countLetters(string S) {
        int res = 0;
        int i = 0;
        while (i < S.size()) {
            int j = i;
            int count = 1;
            while (j+1 < S.size() && S[j+1] == S[j]) { j++; count++; };
            res = res + count * (count + 1) / 2;
            i = j + 1;
        }
        return res;
    }
};