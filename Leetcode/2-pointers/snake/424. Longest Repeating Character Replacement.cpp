//
// Created by Hoang, Quang on 2019-08-26.
//

class Solution {
public:
    bool ok(unordered_map<char, int> count, int k) {
        if (count.size() == 1) return true;
        int ma = 0;
        int sum = 0;
        for(auto pair: count) {
            sum+= pair.second;
            ma = max(ma, pair.second);
        }
        return  sum - ma <= k;
    }

    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0, j = 0, res = 0;

        unordered_map<char, int> count;
        count[s[i]]++;

        while (i < n) {
            if (ok(count, k)) {
                res = max(res, i - j + 1);
                i++;
                if (i < n) {
                    count[s[i]]++;
                }
            } else {
                while (!ok(count, k)) {
                    count[s[j]]--;
                    j++;
                }
            }
        }
        return res;
    }
};