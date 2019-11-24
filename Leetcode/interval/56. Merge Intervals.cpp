class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& b) {
        vector<vector<int>> res;
        int n = b.size();
        vector<pair<int, int>> a;
        for(auto i: b) {
            a.push_back(make_pair(i[0], i[1]));
        }
        sort(a.begin(), a.end());
        int i = 0;
        while (i < n) {
            int j = i;
            int end = a[i].second;
            
            while (j + 1 < n && a[j+1].first <= end) {
                j++;
                end = max(end, a[j].second);
            }
            res.push_back({ a[i].first, end });
            i = j + 1;
        }
        return res;
    }
};