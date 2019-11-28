class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n = a.size();
        int res = 0;
        if (n == 0) return 0;
        int sum[n];
        unordered_map<int, int> count;
        sum[0] = a[0];
        count[0] = 1;
        for(int i = 0; i < n; i++) {
            sum[i] = i == 0 ? a[0] : sum[i-1] + a[i];
            res += count[sum[i] - k];
            count[sum[i]]++;
        }
        return res;
    }
};