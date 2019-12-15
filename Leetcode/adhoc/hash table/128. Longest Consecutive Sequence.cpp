//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> s;
        for (int i: nums) s.insert(i);
        int res = 0;
        while (!s.empty()) {
            int x = *s.begin();
            s.erase(x);
            int lower = x;
            while (s.count(lower - 1) != 0) {
                s.erase(--lower);
            }
            int upper = x;
            while (s.count(upper + 1) != 0) {
                s.erase(++upper);
            }
            res = max(upper - lower + 1, res);
        }
        return res;
    }
};
