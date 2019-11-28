class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n = a.size();
        int res = a[0];
        int left = 1;
        for(int i = 0; i < n; i++) {
            if (left == 0) left = 1;
            left = left * a[i];
            res = max(res, left);
        }
        int right = 1;
        for(int i = n-1; i >= 0; i--) {
            if (right == 0) right = 1;
            right = right * a[i];
            res = max(res, right);
        }
        return res;
    }
};