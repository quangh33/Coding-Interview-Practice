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
    unordered_map<TreeNode *, TreeNode *> pa;

    void dfs(TreeNode *u, TreeNode *v) {
        if (!u) return;
        pa[u] = v;
        dfs(u->left, u);
        dfs(u->right, u);
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, NULL);
        unordered_set < TreeNode * > ancestors;
        while (p) {
            ancestors.insert(p);
            p = pa[p];
        }

        while (ancestors.count(q) == 0) {
            q = pa[q];
        }
        return q;
    }
};