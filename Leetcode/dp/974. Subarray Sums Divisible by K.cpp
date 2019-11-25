//
// Created by Hoang, Quang on 2019-11-21.
//

class Solution {
public:
    int subarraysDivByK(vector<int> &A, int K) {
        int n = A.size();
        int s[n];
        s[0] = A[0];
        for (int i = 1; i < n; i++) s[i] = s[i - 1] + A[i];
        for (int i = 0; i < n; i++) s[i] = (s[i] % K + K) % K;
        unordered_map<int, int> count;

        int res = 0;
        count[0] = 1;
        for (int i = 0; i < n; i++) {
            res = res + count[s[i]];
            count[s[i]]++;
        }

        return res;
    }
};
