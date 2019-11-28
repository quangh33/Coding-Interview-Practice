class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, map<int, string>> store;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        map<int, string>::iterator i = store[key].upper_bound(timestamp);
        if (i == store[key].begin()) return "";
        return (*(--i)).second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */