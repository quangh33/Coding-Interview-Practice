//
// Created by Hoang, Quang on 2019-12-31.
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
    int deepestLeavesSum(TreeNode *root) {
        queue < TreeNode * > q;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            int n = q.size();
            res = 0;
            for (int i = 1; i <= n; i++) {
                TreeNode *u = q.front();
                res = res + u->val;
                q.pop();
                if (u->left) q.push(u->left);
                if (u->right) q.push(u->right);
            }
        }
        return res;
    }
};