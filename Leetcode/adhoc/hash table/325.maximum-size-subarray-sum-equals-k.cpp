class Solution {
public:
    int maxSubArrayLen(vector<int> &a, int k) {
        int n = a.size();
        unordered_map<int, int> pos;
        pos[0] = -1;
        int sum = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (pos.count(sum) == 0) {
                pos[sum] = i;
            }
            int target = sum - k;
            if (pos.count(target) != 0)
                res = max(res, i - pos[target]);
        }
        return res;
    }
};
