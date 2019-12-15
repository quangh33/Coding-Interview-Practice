//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    unordered_map<string, int> count;

    void update(string s, int delta) {
        count[s] += delta;
        while (s.find(".") != string::npos) {
            int i = s.find(".");
            string t = s.substr(i + 1, s.size() - i);
            count[t] += delta;
            s = t;
        }
    }

    vector <string> subdomainVisits(vector <string> &cpdomains) {
        for (string domain: cpdomains) {
            int i = domain.find(" ");
            int delta = stoi(domain.substr(0, i));
            string s = domain.substr(i + 1, domain.size() - i);
            update(s, delta);
        }
        vector <string> res;
        for (auto pair: count) {
            string s = to_string(pair.second) + " " + pair.first;
            res.push_back(s);
        }

        return res;
    }
};