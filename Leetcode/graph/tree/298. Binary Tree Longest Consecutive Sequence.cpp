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

    int res = 0;

    int dfs(TreeNode *u) {
        if (!u) return 0;
        if (!u->left && !u->right) {
            res = max(res, 1);
            return 1;
        }

        int left = dfs(u->left);
        int right = dfs(u->right);

        int longest = 1;
        if (u->left && u->val == u->left->val - 1) longest = max(longest, left + 1);
        if (u->right && u->val == u->right->val - 1) longest = max(longest, right + 1);
        res = max(res, longest);
        return longest;
    }

    int longestConsecutive(TreeNode *root) {
        dfs(root);
        return res;
    }
};