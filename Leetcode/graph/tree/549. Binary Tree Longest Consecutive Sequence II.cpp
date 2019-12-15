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
    int res;

    // return { dec, inc } the maximum decresing/incresing path start from node u go downward
    vector<int> dfs(TreeNode* u) {
        if (!u->left && !u->right) {
            res = max(res, 1);
            return { 1, 1 };
        }

        int inc = 1, dec = 1;

        if (u->left) {
            vector<int> leftResult = dfs(u->left);
            if (u->val + 1 == u->left->val) inc = max(inc, 1 + leftResult[1]);
            if (u->val - 1 == u->left->val) dec = max(dec, 1 + leftResult[0]);
        }

        if (u->right) {
            vector<int> rightResult = dfs(u->right);
            if (u->val + 1 == u->right->val) inc = max(inc, 1 + rightResult[1]);
            if (u->val - 1 == u->right->val) dec = max(dec, 1 + rightResult[0]);
        }

        res = max(res, inc + dec - 1);
        return { dec, inc };
    }

    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        res = 0;
        dfs(root);
        return res;
    }
};