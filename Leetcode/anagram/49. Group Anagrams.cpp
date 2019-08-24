//
// Created by Hoang, Quang on 2019-08-23.
//
// https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> res;
        map<string, vector<string>> m;

        int count[26];
        for(string s: strs) {
            memset(count, 0, sizeof(count));
            string hash = "";
            for(char c: s) count[c - 'a']++;

            for(int i = 0; i < 26; i++) {
                hash = hash + "#";
                hash = hash + to_string(count[i]);
            }
            // cout<<hash<<endl;
            if (m.find(hash) == m.end()) m[hash] = vector<string>();
            m[hash].push_back(s);
        }

        for(auto pair: m) {
            res.push_back(pair.second);
        }
        return res;
    }
};