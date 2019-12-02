//
// Created by Hoang, Quang on 2019-08-09.
//

// https://leetcode.com/problems/peak-index-in-a-mountain-array/

#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        for(int i = 1; i < a.size() - 1; i++) {
            if (a[i] > a[i-1] && a[i] > a[i+1]) return i;
        }
        return 0;
    }
};

