class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            int index = abs(a[i]) - 1;
            a[index] = -a[index];
            if (a[index] > 0) return index+1;
        }
        return 0;
    }
};