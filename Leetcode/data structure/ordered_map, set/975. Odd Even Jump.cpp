//
// Created by Hoang, Quang on 2019-12-01.
//

class Solution {
public:
    int oddEvenJumps(vector<int> &a) {
        int n = a.size();
        int res = 1;
        int bigger[n], smaller[n];
        bool odd[n], even[n];

        memset(odd, false, sizeof(odd));
        memset(even, false, sizeof(even));

        odd[n - 1] = true;
        even[n - 1] = true;

        bigger[n - 1] = n;
        smaller[n - 1] = n;

        map<int, int> m;
        m[a[n - 1]] = n - 1;

        for (int i = n - 2; i >= 0; i--) {
            int val = a[i];

            map<int, int>::iterator it = m.lower_bound(val);
            if (it != m.end()) bigger[i] = (*it).second;
            else bigger[i] = n;

            it = m.upper_bound(val);
            if (it != m.begin()) {
                it--;
                smaller[i] = (*it).second;
            } else smaller[i] = n;

            m[val] = i;
        }

        for (int i = n - 2; i >= 0; i--) {
            if (bigger[i] != n && even[bigger[i]]) odd[i] = true;
            if (smaller[i] != n && odd[smaller[i]]) even[i] = true;
            if (odd[i]) res++;
        }
        return res;
    }
};