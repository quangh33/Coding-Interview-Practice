//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    int fixedPoint(vector<int> &A) {
        int low = 0, high = A.size() - 1;
        int res = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] == mid) {
                res = mid;
                high = mid - 1;
            } else if (A[mid] > mid) high = mid - 1;
            else low = mid + 1;
        }
        return res;
    }
};