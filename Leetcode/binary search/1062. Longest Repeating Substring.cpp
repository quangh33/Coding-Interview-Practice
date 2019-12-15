//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    bool ok(int l, string S) {
        unordered_set <string> seen;
        for (int i = 0; i < S.size() - l + 1; i++) {
            string t = S.substr(i, l);
            if (seen.find(t) != seen.end()) return true;
            seen.insert(t);
        }
        return false;
    }

    int longestRepeatingSubstring(string S) {
        int n = S.size();
        int low = 1, high = n;
        int res;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (ok(mid, S)) {
                res = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        return res;
    }
};