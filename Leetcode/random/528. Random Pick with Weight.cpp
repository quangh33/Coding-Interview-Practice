//
// Created by Hoang, Quang on 2019-11-20.
//

class Solution {
public:
    int sum = 0;
    vector<int> s;
    mt19937 rng{random_device{}()};
    uniform_int_distribution<int> uni;

    Solution(vector<int>& w) {
        s = vector<int>(w.size(), 0);
        s[0] = w[0];
        for(int i = 1; i < w.size(); i++)
            s[i] = s[i-1] + w[i];

        sum = s[w.size()-1];
        uni = uniform_int_distribution<int>{0, sum - 1};
    }

    int pickIndex() {
        int r = uni(rng);
        return upper_bound(s.begin(), s.end(), r) - s.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */