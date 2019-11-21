//
// Created by Hoang, Quang on 2019-11-21.
//

class Solution {
public:
    int delta(int t, int lower, int upper) {
        if (t < lower) return -1;
        if (t > upper) return 1;
        return 0;
    }

    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int point = 0;
        int T = 0;
        for(int i = 0; i < k; i++) T += calories[i];
        point = delta(T, lower, upper);
        int n = calories.size();
        for(int i = k; i < n; i++) {
            T -= calories[i-k];
            T += calories[i];
            point += delta(T, lower, upper);
        }
        return point;
    }
};
