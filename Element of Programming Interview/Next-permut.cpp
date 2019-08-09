#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/*
 * 6.10 - Page 76
 *
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

 - Idea:
    - find the longest decreasing suffix array: a[k-1] < a[k] >= a[k+1] >= .. >= a[n-1];
    - find j in [k, n-1]: a[j] > a[k-1] and j max
    - swap(a[j], a[k-1])
    - sort ascending a[k]..a[n-1]
    
 */

void sort(vector<int>& nums, int u, int v) {
    while (u<=v) {
        swap(nums[u], nums[v]);
        u++;
        v--;
    }
}
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    if (n==0) return;
    int i = n-1;
    while (i-1 >= 0 && nums[i-1] >= nums[i]) i--;
    if (i == 0) {
        sort(nums, 0, n-1);
    } else {
        for(int j = n-1; j >= i; j--)
            if (nums[j] > nums[i-1]) {
                swap(nums[j], nums[i-1]);
                break;
            }
        sort(nums, i, n-1);
    }
}

int main() {
    vector<int> a = {6, 2, 1, 5, 4, 3, 0};
    nextPermutation(a);
    for(int i: a) cout<<i<<endl;
}