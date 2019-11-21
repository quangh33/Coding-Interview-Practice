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
    unordered_map<int, int> count;

    void dfs(TreeNode* u, int cur, int target, int& res) {
	if (!u) return;
        int now = cur + u->val;
	res += count[now - target];
        count[now] ++;
        dfs(u->left, cur + u->val, target, res);
	dfs(u->right, cur + u->val, target, res);
	count[now]--;
    }

    int pathSum(TreeNode* root, int sum) {
	int res = 0;
	count[0] = 1;
	dfs(root, 0, sum, res);
	return res;        
    }
};
