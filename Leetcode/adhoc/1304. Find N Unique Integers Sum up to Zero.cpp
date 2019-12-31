//
// Created by Hoang, Quang on 2019-12-31.
//

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> a = vector<int>(n);
        for(int i = 0; i < n/2 * 2; i+=2) {
            a[i] = i+1;
            a[i+1] = -(i+1);
        }
        if (n % 2 == 1)
            a[n-1] = 0;
        return a;
    }
};