class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> fx = vector<int>(n+1, INT_MAX);
        fx[0] = INT_MIN;
        
        for(int j = 0; j < n; j++) {
            for(int i = 1; i <= n; i++) 
                if (fx[i-1] < a[j]) 
                    fx[i] = min(fx[i], a[j]);
            
            for(int i = 1; i <= n; i++) cout<<fx[i]<<" ";
            cout<<endl;
        }
            
        for(int i = n; i >= 1; i--)
            if (fx[i] != INT_MAX) return i;
        
        return 0;
    }
};