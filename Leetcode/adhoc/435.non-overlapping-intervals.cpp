class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), [](const vector<int>& u, const vector<int>& v) {
		return u[1] < v[1];
	});
	int n = a.size();
	if (n == 0) return 0;
	int end = a[0][1];
	int count = 1;
	for(int i = 1; i < n; i++) {
		if (a[i][0] >= end) {
			end = a[i][1];
			count++;
		}
	}
	return n - count;
    }
};
