//
// Created by Hoang, Quang on 2019-12-15.
//

class TwoSum {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> count;

    TwoSum() {
        count.clear();
    }

    /** Add the number to an internal data structure.. */
    void add(int number) {
        count[number]++;
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto pair: count) {
            int x = pair.first;
            int y = value - x;

            if (count.find(y) != count.end()) {
                if (x != y) return true;
                if (x == y && count[x] > 1) return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */