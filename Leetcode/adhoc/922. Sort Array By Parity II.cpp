//
// Created by Hoang, Quang on 2019-08-25.
//

// https://leetcode.com/problems/sort-array-by-parity-ii/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int boundary = 0;
        int n = A.size();
        for(int i = 0; i < n; i++) {
            if (A[i] % 2 == 0) {
                swap(A[i], A[boundary++]);
            }
        }
        int i = 1;
        int j = n - 2;
        while (i < j) {
            swap(A[i], A[j]);
            i+=2;
            j-=2;
        }
        return A;
    }
};
