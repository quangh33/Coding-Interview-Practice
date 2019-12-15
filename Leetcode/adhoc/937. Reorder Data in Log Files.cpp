//
// Created by Hoang, Quang on 2019-12-15.
//

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digitLog, letterLog;
        for(string log: logs) {
            int i = log.find(' ');
            if (log[i+1] >= '0' && log[i+1] <= '9')
                digitLog.push_back(log);
            else letterLog.push_back(log);
        }

        sort(letterLog.begin(), letterLog.end(), [](string a, string b) {
            int n = a.size();
            int m = b.size();
            int i = a.find(' ');
            int j = b.find(' ');
            string aWord = a.substr(i + 1, n - i - 1);
            string aId = a.substr(0, i);
            string bWord = b.substr(j + 1, m - j - 1);
            string bId = b.substr(0, j);
            return (aWord < bWord || (aWord == bWord && aId < bId));
        });

        for(int i = 0; i < logs.size(); i++)
            if (i < letterLog.size())
                logs[i] = letterLog[i];
            else
                logs[i] = digitLog[i - letterLog.size()];

        return logs;
    }
};
