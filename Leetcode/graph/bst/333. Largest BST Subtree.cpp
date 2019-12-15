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
    int ans = 1;

    // max, min, number of node, isBST
    vector<int> dfs(TreeNode *u) {
        if (!u) {
            return {INT_MIN, INT_MAX, 0, true};
        }
        vector<int> res = vector<int>(4);
        vector<int> left = dfs(u->left);
        vector<int> right = dfs(u->right);

        res[0] = max(u->val, max(left[0], right[0]));
        res[1] = min(u->val, min(left[1], right[1]));
        res[2] = 1 + left[2] + right[2];
        res[3] = left[3] && right[3] && (u->val > left[0]) && (u->val < right[1]);
        if (res[3]) ans = max(ans, res[2]);
        return res;
    }

    int largestBSTSubtree(TreeNode *root) {
        if (!root) return 0;
        dfs(root);
        return ans;
    }
};