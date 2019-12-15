//
// Created by Hoang, Quang on 2019-08-24.
//

// https://leetcode.com/problems/jump-game-ii/

/*
 * let "furthest" be the furthest position we can reach at the moment
 * i = the current position
 * so the optimal next step is the position nextStep ( i < nextStep <= furthest) that from nextStep we can
 * increase reach maximum position.
 */
class Solution {
public:
    int jump(vector<int> &a) {
        int step = 0;
        int i = 0;
        int n = a.size();
        int furthest = 0;
        while (true) {
            if (furthest >= n - 1) break;
            int nextStep, temp = furthest;
            for (int j = i; j <= temp; j++) {
                if (j + a[j] > furthest) {
                    nextStep = j;
                    furthest = j + a[j];
                }
            }
            i = nextStep;
            step++;
        }
        return step;
    }
};
