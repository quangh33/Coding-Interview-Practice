class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        vector<int>::iterator lower, upper;
        lower = lower_bound(nums.begin(), nums.end(), target);
        upper = upper_bound(nums.begin(), nums.end(), target);
        if (lower != nums.end()) {
            int index = lower - nums.begin();
            if (nums[index] == target) {
                res.push_back(lower - nums.begin());
                res.push_back(upper - nums.begin() - 1);   
                return res;
            }
        }
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
};

class Solution {
public:
    int binarySearch(vector<int> nums, int target, bool greater) {
        int lo = 0;
        int hi = nums.size()-1;
        int res = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (greater) {
                if (nums[mid] > target) {
                    res = mid;
                    hi = mid - 1;
                } else lo = mid + 1;
            } else {
                if (nums[mid] >= target) {
                    if (nums[mid] == target) res = mid;
                    hi = mid - 1;
                } else lo = mid + 1;
            }
        }
        return res;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        nums.push_back(INT_MAX);
        vector<int> res = { -1, -1 };
        int index = binarySearch(nums, target, false);
        if (index == -1) return res;
        res[0] = index;
        index = binarySearch(nums, target, true);
        res[1] = index - 1;
        return res;
    }
};