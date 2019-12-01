//
// Created by Hoang, Quang on 2019-12-01.
//

class SummaryRanges {
    set<int> s;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        s = set<int>();
    }


    // O(log n)
    void addNum(int val) {
        s.insert(val);
    }

    // O(n)
    vector <vector<int>> getIntervals() {
        vector<int> a;
        vector <vector<int>> res;

        for (auto i: s) {
            a.push_back(i);
        }

        int i = 0, n = a.size();

        while (i < n) {
            int j = i;
            while (j + 1 < n && a[j + 1] == a[j] + 1) j++;
            res.push_back({a[i], a[j]});
            i = j + 1;
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */