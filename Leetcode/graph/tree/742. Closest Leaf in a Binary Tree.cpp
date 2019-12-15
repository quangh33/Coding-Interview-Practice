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
    unordered_map<TreeNode *, vector < TreeNode * >> a;
    unordered_set<TreeNode *> seen;

    void dfs(TreeNode *u, TreeNode *p) {
        if (!u) return;
        if (p) {
            if (a.count(u) == 0) a[u] = {};
            if (p && a.count(p) == 0) a[p] = {};
            a[u].push_back(p);
            a[p].push_back(u);
        }

        dfs(u->left, u);
        dfs(u->right, u);
    }

    int findClosestLeaf(TreeNode *root, int k) {
        if (!root->left && !root->right) return root->val;
        dfs(root, NULL);
        queue < TreeNode * > q;

        for (auto pair: a)
            if (pair.first->val == k) {
                seen.insert(pair.first);
                q.push(pair.first);
            }

        while (!q.empty()) {
            TreeNode *u = q.front();
            if (!u->left && !u->right) return u->val;
            q.pop();
            for (TreeNode *v: a[u]) {
                if (seen.count(v) == 0) {
                    seen.insert(v);
                    q.push(v);
                }
            }
        }
        return -1;
    }
};