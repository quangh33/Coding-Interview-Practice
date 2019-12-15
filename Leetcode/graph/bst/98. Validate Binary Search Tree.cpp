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
    bool ok(TreeNode *root, long long mi, long long ma) {
        if (!root) return true;
        if (root->val <= mi || root->val >= ma) return false;
        return ok(root->left, mi, root->val) && ok(root->right, root->val, ma);
    }

    bool isValidBST(TreeNode *root) {
        return ok(root, LLONG_MIN, LLONG_MAX);
    }
};