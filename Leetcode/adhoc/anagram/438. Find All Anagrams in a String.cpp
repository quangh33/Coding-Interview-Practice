//
// Created by Hoang, Quang on 2019-08-23.
//

// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:

    bool isPrime(int n) {
        if (n < 2) return false;
        if (n == 2) return true;
        for(int i = 2; i < sqrt(n) + 1; i++) if (n % i == 0) return false;
        return true;
    }

    vector<int> calPrime() {
        vector<int> p;
        for(int i = 2; i < 200; i++)
            if (isPrime(i)) p.push_back(i);
        return p;
    }

    long long hash(string s, vector<int> primes) {
        int mode = 1e9+7;
        long long hashValue = 1;
        for(char c: s)  hashValue = (hashValue * primes[c - 'a']) % mode;
        return hashValue;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> primes = calPrime();
        int n = s.size();
        int m = p.size();

        long long pHash = hash(p, primes);
        vector<int> res;

        for(int i = 0; i < n - m + 1; i++) {
            string slide = s.substr(i, m);
            if (hash(slide, primes) == pHash) res.push_back(i);
        }
        return res;
    }
};
