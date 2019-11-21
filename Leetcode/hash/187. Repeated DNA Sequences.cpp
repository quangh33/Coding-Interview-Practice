//
// Created by Hoang, Quang on 2019-09-25.
//

// https://leetcode.com/problems/repeated-dna-sequences/

class Solution {
public:
    unordered_map<long long, int> count;
    vector<long long> hash;
    vector<long long> pow;
    unordered_map<char, int> m;
    long long MOD = 1e9 + 7;

    vector<string> findRepeatedDnaSequences(string s) {
        m['A'] = 0;
        m['C'] = 1;
        m['G'] = 2;
        m['T'] = 3;
        vector<string> res;

        int n = s.size();
        if (n <= 10) return res;

        hash = vector<long long>(n);
        pow = vector<long long>(n+1);

        pow[0] = 1;
        for(int i = 1; i <= n; i++)
            pow[i] = (pow[i-1] * 4) % MOD;

        hash[0] = m[s[0]];
        for(int i = 1; i < n; i++)
            hash[i] = (hash[i-1] * 4 + m[s[i]]) % MOD;

        for(int i = 9; i < n; i++) {
            long long y = i-10 >= 0 ? hash[i-10] : 0;
            long long x = (hash[i] - y * pow[10] + MOD * MOD) % MOD;
            count[x]++;
            if (count[x] == 2) res.push_back(s.substr(i-9, 10));
        }
        return res;
    }
};