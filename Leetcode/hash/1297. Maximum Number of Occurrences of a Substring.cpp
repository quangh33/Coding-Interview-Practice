//
// Created by Hoang, Quang on 2019-12-31.
//

class Solution {
public:
    // O(n*minSize)
    int maxFreq2(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();
        unordered_map<string, int> count;
        for(int i = 0; i < n - minSize + 1; i++) {
            unordered_set<char> d;
            string t = "";
            for(int j = i; j <= i + minSize - 1; j++) {
                t = t + s[j];
                d.insert(s[j]);
            }
            if (d.size() <= maxLetters)
                count[t]++;
        }

        int res = 0;
        for(auto pair: count)
            res = max(res, pair.second);

        return res;
    }

    // O(n)
    long long BASE = 311;
    long long MOD = 1e9 + 7;

    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<long long, int> count;

        int n = s.size();
        long long hash[n];
        long long pow[n];
        pow[0] = 1;
        for(int i = 1; i < n; i++)
            pow[i] = (pow[i-1] * BASE) % MOD;

        hash[0] = int(s[0]);
        for(int i = 1; i < n; i++)
            hash[i] = (hash[i-1] * BASE + int(s[i])) % MOD;

        int d = 0;
        unordered_map<char, int> freq;

        for(int i = 0; i < minSize; i++) {
            freq[s[i]]++;
            if (freq[s[i]] == 1) d++;
        }

        for(int i = 0; i < n - minSize + 1; i++) {
            int j = i + minSize - 1;
            long long hashValue = i == 0 ? hash[j] :
                                  (hash[j] - hash[i-1] * pow[j-i+1] + MOD * MOD) % MOD;

            if (d <= maxLetters) {
                count[hashValue]++;
                cout<<s.substr(i, minSize)<<endl;
            }

            freq[s[i]]--;
            if (freq[s[i]] == 0) d--;
            if (j + 1 < n) {
                freq[s[j+1]]++;
                if (freq[s[j+1]] == 1) d++;
            }
        }

        int res = 0;
        for(auto pair: count)
            res = max(res, pair.second);

        return res;
    }
};