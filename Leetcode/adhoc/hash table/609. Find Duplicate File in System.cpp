//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
    unordered_map<string, vector<string>> m;
public:
    void process(string s) {
        int i = s.find(' ');
        string dir = s.substr(0, i);
        string t = s.substr(i+1, s.size() - i) + " ";
        string file = "";
        for(int i = 0; i < t.size(); i++)
            if (t[i] == ' ') {
                int i = file.find('(');
                string filename = file.substr(0, i);
                string content = file.substr(i+1, file.size() - i - 2);
                m[content].push_back(dir + "/" + filename);

                // cout<<content<<" "<<dir + "/" + filename<<endl;
                file = "";
            } else file += t[i];
    }

    vector<vector<string>> findDuplicate(vector<string>& paths) {
        for(string path: paths) process(path);
        vector<vector<string>> res;
        for(auto v: m)
            if (v.second.size() > 1) res.push_back(v.second);
        return res;
    }
};