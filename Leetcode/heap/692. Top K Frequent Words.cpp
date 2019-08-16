//
// Created by Hoang, Quang on 2019-08-16.
//

// https://leetcode.com/problems/top-k-frequent-words/

typedef pair<int, string> ps;

class myComp {
public:
    int operator()(const ps &a, const ps &b) {
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    }
};

vector <string> topKFrequent(vector <string> &words, int k) {
    unordered_map<string, int> count;
    for (string s: words) count[s]++;

    priority_queue <ps, vector<ps>, myComp> q;
    unordered_map<string, int>::iterator it;

    for (auto it: count) {
        string s = it.first;
        q.push(make_pair(count[s], s));
        if (q.size() > k) q.pop();
    }

    vector <string> res;
    while (q.size() > 0) {
        res.push_back(q.top().second);
        q.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}