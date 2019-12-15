//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    bool can(string s, string t) {
        int diff = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] != t[i]) {
                diff++;
                if (diff > 1) return false;
            }
        return diff == 1;
    }

    int ladderLength(string beginWord, string endWord, vector <string> &wordList) {
        int n = wordList.size() + 1;
        bool ok = false;
        for (string word: wordList)
            if (word == endWord) {
                ok = true;
                break;
            }

        if (!ok) return 0;

        vector<int> a[n];
        int des;
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == endWord) {
                des = i + 1;
            }
            if (can(beginWord, wordList[i])) {
                a[0].push_back(i + 1);
            }

            for (int j = i + 1; j < wordList.size(); j++)
                if (can(wordList[i], wordList[j])) {
                    a[i + 1].push_back(j + 1);
                    a[j + 1].push_back(i + 1);
                }
        }

        int fx[n];
        for (int i = 0; i < n; i++) fx[i] = -1;

        fx[0] = 0;
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v: a[u]) {
                if (fx[v] == -1) {
                    fx[v] = fx[u] + 1;
                    if (v == des) return fx[v] + 1;
                    q.push(v);
                }
            }
        }

        return 0;
    }
};