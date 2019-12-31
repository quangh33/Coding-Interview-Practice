//
// Created by Hoang, Quang on 2019-12-31.
//

class Solution {
public:
    vector<int> replaceElements(vector<int> &a) {
        int n = a.size();
        int ma = a[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            int temp = a[i];
            a[i] = ma;
            ma = max(ma, temp);
        }
        a[n - 1] = -1;
        return a;
    }
};