class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> a = vector<int>(length, 0);
        for(auto update: updates) {
            int u = update[0];
            int v = update[1];
            int val = update[2];
            a[u]+=val;
            if (v+1 < length) a[v+1]-=val;
        }
        for(int i = 1; i < length; i++)
            a[i] += a[i-1];
        return a;
    }
};
