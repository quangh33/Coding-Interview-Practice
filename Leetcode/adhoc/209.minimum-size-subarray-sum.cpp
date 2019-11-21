class Solution {
public:
    int minSubArrayLen(int s, vector<int>& a) {
	int n = a.size();
	if (n == 0) return 0;
        int res = INT_MAX;
	int i = 0, j = 0;
	int sum = a[0];
	while (i < n) {
		if (sum < s) {
			i++;
			if (i < n) sum += a[i];
		} else {
			res = min(res, i - j + 1);
			sum -= a[j];
			j++;
		}	
	}
	return res == INT_MAX ? 0 : res;
    }
};
