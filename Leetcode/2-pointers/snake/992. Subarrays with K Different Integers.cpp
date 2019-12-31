//
// Created by Hoang, Quang on 2019-12-23.
//

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return subarrayWithMostKDistinct(A, K) - subarrayWithMostKDistinct(A, K-1);
    }

    int subarrayWithMostKDistinct(vector<int> a, int k) {
        int res = 0;
        unordered_map<int, int> count;
        int i = 0;
        int n = a.size();
        int distinct = 0;
        for(int j = 0; j < n; j++) {
            count[a[j]]++;
            if (count[a[j]] == 1) distinct++;
            while (distinct > k) {
                count[a[i]]--;
                if (count[a[i]] == 0) distinct--;
                i++;
            }
            res += (j - i + 1);
        }
        return res;
    }
};