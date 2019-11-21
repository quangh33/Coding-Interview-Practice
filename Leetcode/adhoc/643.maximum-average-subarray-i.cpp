class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
	int n = nums.size();
	double res = INT_MIN;
	for(int i = 1; i < n; i++) 
		nums[i]+=nums[i-1];
	
	for(int i = k-1; i < n; i++) {
		int j = i - k + 1;
		double avg = j == 0 ? 1.0 * nums[i] / k : 1.0 * (nums[i] - nums[j-1]) / k;
		res = max(res, avg);
	}        
	return res;
    }
};
