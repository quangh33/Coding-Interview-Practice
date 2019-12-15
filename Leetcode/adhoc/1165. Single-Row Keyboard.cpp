//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> pos;
        for (int i = 0; i < keyboard.size(); i++) pos[keyboard[i]] = i;
        int res = 0;
        int currentPos = 0;

        for (int i = 0; i < word.size(); i++) {
            res = res + abs(pos[word[i]] - currentPos);
            currentPos = pos[word[i]];
        }

        return res;
    }
};