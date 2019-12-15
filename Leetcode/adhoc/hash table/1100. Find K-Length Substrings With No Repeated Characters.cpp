//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        int n = S.size();
        if (K > n) return 0;
        unordered_set<char> s;
        unordered_map<char, int> count;


        for (int i = 0; i < K; i++) {
            s.insert(S[i]);
            count[S[i]]++;
        }


        int res = 0;
        if (s.size() == K) res++;
        for (int i = K; i < n; i++) {
            count[S[i - K]]--;
            if (count[S[i - K]] == 0) s.erase(S[i - K]);
            s.insert(S[i]);
            count[S[i]]++;

            if (s.size() == K) {
                // cout<<S.substr(i-K+1, K)<<endl;
                res++;
            }
        }

        return res;
    }
};