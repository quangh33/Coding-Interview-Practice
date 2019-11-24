class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size();
        int res[n];
        res[0] = 1;
        for(int i = 1; i < n; i++) res[i] = res[i-1] * a[i-1];
        int r = 1;
        for(int i = n-1; i >= 0; i--) {
            res[i] = res[i] * r;
            r *= a[i];
        };
        return vector<int>(res, res+n);
    }
};