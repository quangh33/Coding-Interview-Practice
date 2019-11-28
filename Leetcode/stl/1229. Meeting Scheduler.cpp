class Solution {
    int res = INT_MAX;
    int duration;
    map<int, int> first, second;
public:
    void find(vector<vector<int>>& slots, map<int, int> m) {
        for(auto a: slots) {
            if (a[1] - a[0] >= duration) {
                int x = a[0];
                map<int, int>::iterator i = m.upper_bound(x); 
                if (i != m.begin()) {
                    i--;
                    if ((*i).second - a[0] >= duration) 
                        res = min(res, a[0]);
                }
            }
        }
    }
    
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        this->duration = duration;
        
        for(auto a: slots1)
            first[a[0]] = a[1];
        
        for(auto a: slots2) 
            second[a[0]] = a[1];
        
        find(slots1, second);
        find(slots2, first);
    
        if (res == INT_MAX) return { };
        return { res, res + duration };
    }
};