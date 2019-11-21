//
// Created by Hoang, Quang on 2019-11-20.
//

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if (n == 0) return 0;
        int bit[n];
        int res = 0;
        for(int i = 0; i < n; i++) {
            string word = words[i];
            bit[i] = 0;
            for(char c: word) {
                int j = c - 'a';
                bit[i] = bit[i] | (1 << j);
            }
        }

        // cout<<bit[0]<<" "<<bit[4]<<" "<<bit[0] && bit[4];
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                if ((bit[i] & bit[j]) == 0) {
                    int x = words[i].size() * words[j].size();
                    res = max(res, x);
                }

        return res;
    }
};