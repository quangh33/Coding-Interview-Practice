//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    unordered_map<int, int> p;
    unordered_map<int, int> r;
    unordered_map<int, int> count;

    int find(int i) {
        if (i == p[i]) return i;
        return find(p[i]);
    }

    void merge(int i, int j) {
        if (r[i] > r[j]) {
            p[j] = i;
            count[i] += count[j];
        } else {
            p[i] = j;
            count[j] += count[i];
            if (r[i] == r[j]) r[j]++;
        }
    }

    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> exist;
        vector<int> distinct;

        for (int i: nums) {
            if (exist.count(i) == 0) {
                exist.insert(i);
                p[i] = i;
                r[i] = 0;
                count[i] = 1;
                distinct.push_back(i);
            }
        }

        for (int i: distinct) {
            if (exist.count(i - 1) != 0) {
                int u = find(i);
                int v = find(i - 1);
                if (u != v) merge(u, v);
            }

            if (exist.count(i + 1) != 0) {
                int u = find(i);
                int v = find(i + 1);
                if (u != v) merge(u, v);
            }
        }
        int res = 0;
        for (int i: distinct) {
            res = max(res, count[i]);
        }
        return res;
    }
};