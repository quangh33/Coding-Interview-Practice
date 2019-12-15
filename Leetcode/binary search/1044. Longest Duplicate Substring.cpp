//
// Created by Hoang, Quang on 2019-08-27.
//

// https://leetcode.com/problems/longest-duplicate-substring/

class Solution {
public:

    long long MOD = 1e9+3;
    long long MOD_2 = 1e9+7;

    int BASE = 311;
    long long h1[100005], h2[100005], pow1[100005], pow2[100005];

    long long hash_1(int i, int j) {
        if (i == 0) return h1[j];
        return (h1[j] - h1[i-1] * pow1[j-i+1] + MOD * MOD) % MOD;
    }

    long long hash_2(int i, int j) {
        if (i == 0) return h2[j];
        return (h2[j] - h2[i-1] * pow2[j-i+1] + MOD_2 * MOD_2) % MOD_2;
    }

    string ok(string s, int k) {
        unordered_map<long long, int> count1;
        unordered_map<long long, int> count2;
        for(int i = 0; i < s.size() - k + 1; i++) {
            long long u = hash_1(i, i + k - 1);
            long long v = hash_2(i, i + k - 1);
            count1[u]++;
            count2[v]++;
            if (count1[u] == 2 && count2[v] == 2) return s.substr(i, k);
        }
        return "@";
    }


    string longestDupSubstring(string S) {
        int n = S.size();
        pow1[0] = 1;
        for(int i = 1; i <= n; i++)
            pow1[i] = (pow1[i-1] * BASE) % MOD;

        pow2[0] = 1;
        for(int i = 1; i <= n; i++)
            pow2[i] = (pow2[i-1] * BASE) % MOD_2;

        h1[0] = int(S[0]);
        for(int i = 1; i < n; i++)
            h1[i] = (h1[i-1] * BASE % MOD + int(S[i])) % MOD;

        h2[0] = int(S[0]);
        for(int i = 1; i < n; i++)
            h2[i] = (h2[i-1] * BASE % MOD_2 + int(S[i])) % MOD_2;

        int lo = 1;
        int hi = n;
        string res = "";
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            string check = ok(S, mid);
            if (check != "@") {
                res = check;
                lo = mid + 1;
            } else
                hi = mid - 1;
        }

        return res;
    }
};