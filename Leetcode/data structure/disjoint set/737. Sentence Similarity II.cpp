//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    int p[2001];
    int r[2001];

    int find(int i) {
        if (i == p[i]) return i;
        return find(p[i]);
    }

    void merge(int i, int j) {
        if (r[i] > r[j]) {
            p[j] = i;
        } else {
            p[i] = j;
            if (r[i] == r[j]) r[j]++;
        }
    }

    bool areSentencesSimilarTwo(vector <string> &words1, vector <string> &words2, vector <vector<string>> &pairs) {
        unordered_map<string, int> index;
        int n = 0;
        if (words1.size() != words2.size()) return false;

        for (string s: words1)
            if (index.count(s) == 0) index[s] = n++;

        for (string s: words2)
            if (index.count(s) == 0) index[s] = n++;

        for (auto pair: pairs) {
            if (index.count(pair[0]) == 0) index[pair[0]] = n++;
            if (index.count(pair[1]) == 0) index[pair[1]] = n++;
        }

        for (int i = 0; i < n; i++) {
            p[i] = i;
            r[i] = 0;
        }

        for (auto pair: pairs) {
            string x = pair[0];
            string y = pair[1];

            int rootX = find(index[x]);
            int rootY = find(index[y]);
            merge(rootX, rootY);
        }

        for (int i = 0; i < words1.size(); i++) {
            if (find(index[words1[i]]) != find(index[words2[i]])) {

                return false;
            }
        }
        return true;
    }
};