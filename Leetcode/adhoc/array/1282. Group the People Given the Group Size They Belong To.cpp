//
// Created by Hoang, Quang on 2020-01-02.
//

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        int n = groupSizes.size();
        vector<int> sameSize[n+1];
        unordered_set<int> sizes;

        for(int i = 0; i < n; i++) {
            sameSize[groupSizes[i]].push_back(i);
            sizes.insert(groupSizes[i]);
        }

        for(auto size: sizes) {
            vector<int> a;
            for(int i = 0; i < sameSize[size].size(); i++) {
                a.push_back(sameSize[size][i]);
                if (a.size() == size) {
                    res.push_back(a);
                    a.clear();
                }
            }
        }
        return res;
    }
};