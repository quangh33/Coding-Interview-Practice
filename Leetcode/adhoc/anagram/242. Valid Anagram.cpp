//
// Created by Hoang, Quang on 2019-08-23.
//

// https://leetcode.com/problems/valid-anagram/

class Solution {
public:

    map<char, int> count(string s) {
        map<char, int> a;
        for(char c: s) {
            a[c]++;
        }
        return a;
    }

    bool isAnagram(string s, string t) {
        map<char, int> a = count(s);
        map<char, int> b = count(t);
        if (a.size() != b.size()) return false;
        for(auto pair: a) if (pair.second != b[pair.first]) return false;
        return true;
    }
};

