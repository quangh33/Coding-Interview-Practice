//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> c;
        unordered_set<char> distinct;
        for (char o: s) {
            c[o]++;
            distinct.insert(o);
        }
        int odd = 0;
        for (auto o: distinct)
            if (c[o] % 2 == 1) odd++;
        return odd < 2;
    }
};