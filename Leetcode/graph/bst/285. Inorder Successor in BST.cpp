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
    TreeNode *res;
    TreeNode *prev;

    void dfs(TreeNode *u, TreeNode *p) {
        if (!u) return;
        dfs(u->left, p);
        if (prev == p) {
            res = u;
            prev = u;
            return;
        }
        prev = u;
        dfs(u->right, p);
    }

    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        prev = NULL;
        dfs(root, p);
        return res;
    }
};