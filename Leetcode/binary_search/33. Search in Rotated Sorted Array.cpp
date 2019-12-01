class Solution {
    vector<int> a;
    int target;
public:
    int findPivotIndex(int left, int right) {
        if (a[left] < a[right]) return -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (a[mid] > a[mid+1]) {
                return mid+1;
            } else {
                if (a[mid] < a[left]) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
    
    int find(int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (a[mid] == target) return mid;
            if (a[mid] > target) right = mid - 1;
            else left = mid + 1;
        }    
        return -1;
    }
    
    int search(vector<int>& a, int target) {
        this->a = a;
        this->target = target;
        int n = a.size();
        if (n == 0) return -1;
        if (n == 1) return target == a[0] ? 0 : -1;
        int pivotIndex = findPivotIndex(0, n-1);
        if (pivotIndex == -1) return find(0, n-1);
        if (target < a[0]) return find(pivotIndex, n-1);
        return find(0, pivotIndex-1);
    }
};