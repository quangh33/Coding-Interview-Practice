//
// Created by Hoang, Quang on 2019-11-20.
//

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> a;
    unordered_map<int, int> pos;

    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (pos.find(val) != pos.end()) return false;
        a.push_back(val);
        pos[val] = a.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (pos.find(val) == pos.end()) return false;
        int n = a.size();
        pos[a[n-1]] = pos[val];
        swap(a[pos[val]], a[n-1]);
        a.pop_back();
        pos.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int n = a.size();
        return a[rand() % n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */