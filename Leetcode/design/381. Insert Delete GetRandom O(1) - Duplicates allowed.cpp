//
// Created by Hoang, Quang on 2019-11-20.
//

class RandomizedCollection {
public:
    vector<int> a;
    unordered_map<int, unordered_set<int>> pos;

    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool contain = (pos.find(val) != pos.end());
        if (!contain) pos[val] = unordered_set<int>();
        a.push_back(val);
        pos[val].insert(a.size() - 1);
        return !contain;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        int n = a.size();
        bool contain = pos[val].size() > 0;
        if (!contain) return false;
        int positionToErase = *pos[val].begin();
        pos[val].erase(positionToErase);
        swap(a[positionToErase], a[n-1]);
        pos[a[n-1]].insert(positionToErase);
        pos[a[n-1]].erase(n-1);

        a.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return a[rand() % a.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */