//
// Created by Hoang, Quang on 2019-11-21.
//

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> count;
        for(char c: text) count[c]++;
        int res = min(min(count['b'], count['a']),
                      min(min(count['l'] / 2, count['o'] / 2),
                          count['n']));
        return res;
    }
};