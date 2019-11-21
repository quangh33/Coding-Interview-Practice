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
    bool ok;
    int dfs(TreeNode* u) {
	if (!u) return 0;
	int left = dfs(u->left);
	int right = dfs(u->right);
	if (abs(left - right) > 1) ok = false;
	return max(left, right) + 1;
    }    

    bool isBalanced(TreeNode* root) {
	ok = true;
	dfs(root);
	return ok;
    }
};
