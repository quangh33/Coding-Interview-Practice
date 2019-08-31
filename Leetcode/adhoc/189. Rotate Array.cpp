//
// Created by Hoang, Quang on 2019-08-27.
//

class Solution {
public:
    void reverse(vector<int> &a, int i, int j) {
        while (i < j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    void rotate(vector<int>& a, int k) {
        int n = a.size();
        k = k % n;
        reverse(a, 0, n - 1);
        reverse(a, 0, k - 1);
        reverse(a, k, n - 1);
    }
};