class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int n = a.size();
        int index = 0;
        bool exist = false;
        for(int i = 0; i < n; i++)
            if (a[i] > 0 && a[i] <= n) {
                swap(a[i], a[index++]);
                exist = true;
            }
            
        if (!exist) return 1;
        
        n = index;
        for(int i = 0; i < n; i++) {
            int value = abs(a[i]);
            if (a[value-1] > 0) a[value-1] *= -1;
        }
        
        for(int i = 0; i < n; i++)
            if (a[i] > 0)
                return i+1;
        return n+1;
    }
};