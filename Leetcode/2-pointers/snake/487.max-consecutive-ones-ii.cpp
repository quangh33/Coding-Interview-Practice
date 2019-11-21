class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
	int n = nums.size();
	if (n == 0) return 0;
	int res = 0;
	int i = 0, j = 0;
	int count = nums[0] == 0;
	while (i < n) {
		if (count <= 1) {
			res = max(res, i - j + 1);
			i++;
			if (i < n) count+= (nums[i] == 0);
		} else {
			count-= (nums[j] == 0);
			j++;
		}
	}        
	return res;
    }
};
