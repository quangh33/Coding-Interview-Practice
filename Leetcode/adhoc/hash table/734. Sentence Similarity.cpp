//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    bool areSentencesSimilar(vector <string> &words1, vector <string> &words2, vector <vector<string>> &pairs) {
        int n = words1.size();
        int m = words2.size();
        if (n != m) return false;

        unordered_set <string> pairset;
        for (auto pair: pairs)
            pairset.insert(pair[0] + "#" + pair[1]);

        for (int i = 0; i < n; i++) {
            string x = words1[i];
            string y = words2[i];
            if (x == y) continue;
            if (pairset.find(x + "#" + y) == pairset.end() && pairset.find(y + "#" + x) == pairset.end()) return false;
        }

        return true;
    }
};