//
// Created by Hoang, Quang on 2019-12-05.
//

class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> a;
        while (n != 0) {
            int i = n % 10;
            a.push_back(i);
            n = n / 10;
        }
        reverse(a.begin(), a.end());
        n = a.size();
        int i = n - 1;
        while (i - 1 >= 0 && a[i - 1] >= a[i]) i--;
        if (i == 0) return -1;

        i--;
        for (int j = n - 1; j > i; j--)
            if (a[j] > a[i]) {
                swap(a[i], a[j]);
                break;
            }

        long long res = 0;
        for (int j = 0; j <= i; j++)
            res = res * 10 + a[j];

        for (int j = n - 1; j > i; j--)
            res = res * 10 + a[j];

        if (res > INT_MAX) return -1;
        return res;
    }
};