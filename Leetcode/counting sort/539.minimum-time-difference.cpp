class Solution {
public:
    int minute(string s) {
	    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> a;
        for(string s: timePoints) {
            a.push_back(minute(s));
        }

        int count[1450];
        memset(count, 0, sizeof(count));
        for(int i: a) count[i]++;
        for(int i = 1; i < 1450; i++) count[i] += count[i-1];
        int sortedA[a.size()];

        for(int i: a) {
            sortedA[count[i]-1] = i;
            count[i]--;
        }

        int res = INT_MAX;
        for(int i = 1; i < a.size(); i++) {
            res = min(res, sortedA[i] - sortedA[i-1]);
        }

        res = min(res, 23*60+60 - sortedA[a.size()-1] + sortedA[0]);
        return res;
    }
};
