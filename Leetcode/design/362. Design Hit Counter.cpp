//
// Created by Hoang, Quang on 2019-12-15.
//

class HitCounter {
public:
    /** Initialize your data structure here. */
    vector<int> a;

    HitCounter() {

    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        a.push_back(timestamp);
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int mi = timestamp - 300;
        return a.end() - upper_bound(a.begin(), a.end(), mi);
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */