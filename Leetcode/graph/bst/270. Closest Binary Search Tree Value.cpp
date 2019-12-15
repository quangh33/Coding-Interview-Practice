//
// Created by Hoang, Quang on 2019-12-15.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    long long resLess = LLONG_MIN, resMore = LLONG_MAX;

    void findLess(TreeNode *u, double target) {
        if (!u) return;
        if (u->val <= target) {
            resLess = u->val;
            findLess(u->right, target);
        } else findLess(u->left, target);
    }

    void findMore(TreeNode *u, double target) {
        if (!u) return;
        if (u->val >= target) {
            resMore = u->val;
            findMore(u->left, target);
        } else findMore(u->right, target);
    }

    int closestValue(TreeNode *root, double target) {
        findLess(root, target);
        findMore(root, target);
        return (target - resLess < resMore - target ? resLess : resMore);
    }
};