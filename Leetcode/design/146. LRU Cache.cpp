#include<list>
#include<unordered_map>

using namespace std;

class LRUCache {
public:
    unordered_map<int, int> cache;
    // use order of key, front: oldest, back: newest
    list<int> recent;
    unordered_map<int, list<int>::iterator> pos;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
    }

    void use(int key) {
        // key already exist
        if (pos.find(key) != pos.end()) {
            recent.erase(pos[key]);
        } else {
            if (recent.size() == cap) {
                int oldestKey = recent.front();
                recent.pop_front();
                pos.erase(oldestKey);
                cache.erase(oldestKey);
            }
        }

        recent.push_back(key);
        pos[key] = --recent.end();
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        use(key);
        return cache[key];
    }

    void put(int key, int value) {
        use(key);
        cache[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
