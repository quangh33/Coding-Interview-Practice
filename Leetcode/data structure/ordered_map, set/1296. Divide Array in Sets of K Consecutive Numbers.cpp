//
// Created by Hoang, Quang on 2020-01-01.
//

class Solution {
public:
    bool isPossibleDivide(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        set<int> avai;
        unordered_map<int, unordered_set<int>> pos;

        int n = a.size();
        if (n % k != 0) return false;

        for(int i = 0; i < n; i++) avai.insert(i);
        for(int i = 0; i < n; i++)
            pos[a[i]].insert(i);

        while (!avai.empty()) {
            int i = *avai.begin();
            for(int j = a[i]; j < a[i] + k; j++) {
                if (pos[j].size() == 0) return false;
                else {
                    int u = *pos[j].begin();
                    pos[j].erase(u);
                    avai.erase(u);
                }
            }

        }
        return true;
    }
};