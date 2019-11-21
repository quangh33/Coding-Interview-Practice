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
    
    void dfs(TreeNode* u, int currentSum, int& res) {
    	if (!u) return;
	if (!u->left && !u->right) {
		res += currentSum * 10 + u->val;
        	return;
	}
	dfs(u->left, currentSum * 10 + u->val, res);
	dfs(u->right, currentSum * 10 + u->val, res);
    }

    int sumNumbers(TreeNode* root) {
	int res = 0;
	dfs(root, 0, res);
	return res;	        
    }
};
