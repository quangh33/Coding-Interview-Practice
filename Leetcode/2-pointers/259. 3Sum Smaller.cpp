//
// Created by Hoang, Quang on 2019-09-05.
//

class Solution {
public:
    int threeSumSmaller(vector<int>& a, int target) {
        int n = a.size();
        if (n < 3) return 0;
        sort(a.begin(), a.end());
        int res = 0;
        for(int i = 0; i < n-2; i++) {
            int delta = target - a[i];
            // find in i+1 .. n-1: a[u] + a[v] < delta
            int l = i+1;
            int r = n-1;

            while (l < r) {
                int sum = a[l] + a[r];
                if (sum < delta) {
                    res = res + (r - l);
                    l++;
                } else r--;
            }
        }

        return res;
    }
};