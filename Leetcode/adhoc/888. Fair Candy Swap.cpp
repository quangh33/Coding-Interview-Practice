//
// Created by Hoang, Quang on 2019-08-25.
//

// https://leetcode.com/problems/fair-candy-swap/

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum = 0;
        int sumA = 0;
        for(int i: A) sumA+=i;

        sum = sumA;
        for(int i: B) sum+=i;
        sum = sum / 2;
        int delta = sum - sumA;

        map<int, bool> exist;
        for(int i: B) exist[i] = true;
        vector<int> res;
        for(int i: A) {
            int j = delta + i;
            if (exist[j]) {
                res.push_back(i);
                res.push_back(j);
                break;
            }
        }
        return res;
    }
};