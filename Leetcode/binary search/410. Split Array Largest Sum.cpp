//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    bool check(vector<int> a, long long maxSum, int m) {
        int i = 0;
        int count = 0;
        int n = a.size();
        while (i < n) {
            long long currentSum = a[i];
            if (currentSum > maxSum) return false;
            int j = i;
            while (j + 1 < n && currentSum + a[j + 1] <= maxSum) {
                j++;
                currentSum += a[j];
            }
            count++;
            //cout<<i<<" "<<j<<endl;
            i = j + 1;
        }

        return count <= m;
    }

    int splitArray(vector<int> &a, int m) {
        int n = a.size();
        long long h = 0, res;
        for (int i: a) h += i;
        long long l = 0;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (check(a, mid, m)) {
                res = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};