//
// Created by Hoang, Quang on 2019-12-01.
//

class Solution {
public:
    int kEmptySlots(vector<int> &a, int K) {
        set<int> pos;
        int n = a.size();
        pos.insert(a[0]);
        for (int i = 1; i < n; i++) {
            set<int>::iterator next = pos.upper_bound(a[i]);
            if (next != pos.end() && *next - a[i] == K + 1) return i + 1;
            set<int>::iterator prev = pos.lower_bound(a[i]);

            if (prev != pos.begin()) {
                prev--;
                if (a[i] - *prev == K + 1) return i + 1;
            }
            pos.insert(a[i]);
        }
        return -1;
    }
};