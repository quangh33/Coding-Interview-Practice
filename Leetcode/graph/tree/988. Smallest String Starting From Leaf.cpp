//
// Created by Hoang, Quang on 2019-11-22.
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

    string res = "~";

    void dfs(TreeNode *u, string s) {
        if (!u) return;
        string t = s + char(u->val + int('a'));

        if (!u->left && !u->right) {
            reverse(t.begin(), t.end());
            res = min(res, t);
            return;
        }
        dfs(u->left, t);
        dfs(u->right, t);
    }

    string smallestFromLeaf(TreeNode *root) {
        dfs(root, "");
        return res;
    }
};