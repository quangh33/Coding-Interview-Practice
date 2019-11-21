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

    void dfs(TreeNode* u, int& x, int& y) {
	int ma = u->val;
	int mi = u->val;
    	if (!u->left && !u->right) {
		x = ma;
		y = mi;
		res++;
		return;
	}
	if (u->left) {
		int minLeft, maxLeft;
		dfs(u->left, maxLeft, minLeft);
		ma = max(ma, maxLeft);
		mi = min(mi, minLeft);
	}
	if (u->right) {
		int minRight, maxRight;
		dfs(u->right, maxRight, minRight);
		ma = max(ma, maxRight);
		mi = min(mi, minRight);
	}
	if (mi == ma) res++;
	x = ma;
	y = mi;
    }

    int countUnivalSubtrees(TreeNode* root) {
	res = 0;
	if (!root) return res;
	int x;
	dfs(root, x, x);      
	return res;  
    }
};
