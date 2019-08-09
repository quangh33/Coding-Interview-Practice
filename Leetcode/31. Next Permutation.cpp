//
// Created by Hoang, Quang on 2019-08-05.
//

/*
 * https://leetcode.com/problems/next-permutation/
 */


#include <vector>

using namespace std;


void sort(vector<int> &nums, int u, int v) {
    while (u <= v) {
        swap(nums[u], nums[v]);
        u++;
        v--;
    }
}

void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) return;
    int i = n - 1;
    while (i - 1 >= 0 && nums[i - 1] >= nums[i]) i--;
    if (i == 0) {
        sort(nums, 0, n - 1);
    } else {
        for (int j = n - 1; j >= i; j--)
            if (nums[j] > nums[i - 1]) {
                swap(nums[j], nums[i - 1]);
                break;
            }
        sort(nums, i, n - 1);
    }
}

