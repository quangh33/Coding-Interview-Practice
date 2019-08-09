//
// Created by Hoang, Quang on 2019-08-09.
//

// https://leetcode.com/problems/sort-characters-by-frequency/

#include <string>
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    int convert(char c) {
        return int(c);
    }

    static bool sortDescByFirst(const pair<int, char> a, const pair<int, char> b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }

    string frequencySort(string s) {
        int n = s.length();
        int count[300];
        vector<pair<int, char> > freq;
        memset(count, 0, sizeof(count));

        for(int i = 0; i < n; i++) {
            //cout<<s[i]<<" "<<convert(s[i])<<endl;
            count[convert(s[i])]++;
        }
        for(int i = 0; i < n; i++) {
            freq.push_back(make_pair(count[convert(s[i])], s[i]));
        }

        sort(freq.begin(), freq.end(), sortDescByFirst);
        string res = "";
        for(int i = 0; i < n; i++) {
            res+= freq[i].second;
        }
        return res;
    }
};

class Solution2 {
public:
    string frequencySort(string s) {
        int n = s.length();
        int count[256];
        memset(count, 0, sizeof(count));

        priority_queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) count[s[i]]++;
        for(int i = 0; i < 256; i++) {
            if (count[i]) {
                q.push(make_pair(count[i], i));
            }
        }
        string res = "";
        while (!q.empty()) {
            res.append(q.top().first, q.top().second);
            q.pop();
        }
        return res;
    }
};

