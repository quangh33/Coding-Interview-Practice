//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    /*
        def:
            diff: number of way such that 2 last posts are different
            same: ---------------------------------------- the same

            diff = same * (k-1) + diff * (k - 1)
            same = diff

            init: diff = k * (k-1)
                  same = k
    */
    int numWays(int n, int k) {
        if (n == 0) return 0;
        if (n == 1) return k;
        int diff = k * (k - 1);
        int same = k;

        for (int i = 3; i <= n; i++) {
            int prevDiff = diff;
            diff = (same + diff) * (k - 1);
            same = prevDiff;
        }
        return diff + same;
    }
};