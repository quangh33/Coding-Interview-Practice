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
    int res = INT_MIN;

    int dfs(TreeNode *u) {
        if (!u) return 0;
        int left = max(0, dfs(u->left));
        int right = max(0, dfs(u->right));
        res = max(res, left + right + u->val);
        return max(left, right) + u->val;
    }

    int maxPathSum(TreeNode *root) {
        dfs(root);
        return res;
    }
};
