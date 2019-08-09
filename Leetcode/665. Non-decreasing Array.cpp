//
// Created by Hoang, Quang on 2019-08-09.
//

// https://leetcode.com/problems/non-decreasing-array/

#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& a) {
        int n = a.size();
        int wrongIndex = -1;
        for(int i = 0; i < n - 1; i++) {
            if (a[i] > a[i+1]) {
                if (wrongIndex != -1) return false;
                wrongIndex = i;
            }
        }
        if (wrongIndex == -1) return true;
        if (wrongIndex == 0 || wrongIndex == n-2) return true;
        return a[wrongIndex - 1] <= a[wrongIndex + 1] || a[wrongIndex] <= a[wrongIndex + 2];
    }
};