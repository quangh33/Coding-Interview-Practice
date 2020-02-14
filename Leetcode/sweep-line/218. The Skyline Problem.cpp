//
// Created by Hoang, Quang on 2020-02-14.
//

class Solution {
    multiset<int> ms;

    int maxHeight() {
        if (ms.empty()) return 0;
        return *ms.rbegin();
    }

public:
    typedef pair<int, int> II;

    vector <vector<int>> getSkyline(vector <vector<int>> &buildings) {
        vector <pair<int, int>> events;
        for (auto b: buildings) {
            events.push_back({b[0], b[2]});
            events.push_back({b[1], -b[2]});
        }
        sort(events.begin(), events.end(), [](II e1, II e2) {
            if (e1.first == e2.first) return e1.second > e2.second;
            return e1.first < e2.first;
        });

        ms.clear();
        vector <vector<int>> res;

        for (auto e: events) {
            int h = abs(e.second);
            if (e.second > 0) {
                if (h > maxHeight())
                    res.push_back({e.first, h});
                ms.insert(h);
            } else {
                ms.erase(ms.equal_range(h).first);
                if (h > maxHeight())
                    res.push_back({e.first, maxHeight()});
            }
        }
        return res;
    }
};