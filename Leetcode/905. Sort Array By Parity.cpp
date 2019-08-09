//
// Created by Hoang, Quang on 2019-08-09.
//
// https://leetcode.com/problems/sort-array-by-parity/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int boundary = 0;
        int n = A.size();
        for(int i = 0; i < n; i++) {
            if (A[i] % 2 == 0) {
                swap(A[i], A[boundary++]);
            }
        }
        return A;
    }
};

