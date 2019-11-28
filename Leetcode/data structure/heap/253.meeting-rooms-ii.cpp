class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> x, vector<int> y) {
            return x[0] < y[0];
        });

	    map<int, int> a;
	    for(auto meeting: intervals) {
	        int s = meeting[0];
	        int e = meeting[1];
	        a[s]++;
	        a[e]--;
	    }

	    int count = 0;
	    int res = 0;
	    for(auto pair: a) {
	        count += pair.second;
	        res = max(res, count);
	    }
	    return res;
    }
};
