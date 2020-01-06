//
// Created by Hoang, Quang on 2020-01-06.
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
    unordered_map<TreeNode *, TreeNode *> pa;
    unordered_map<TreeNode *, int> h;
    int maxH = -1;
    unordered_set<TreeNode *> s;
public:
    void dfs(TreeNode *u, int i) {
        h[u] = i;
        if (i > maxH) {
            maxH = i;
            s.clear();
            s.insert(u);
        } else if (i == maxH) {
            s.insert(u);
        }

        if (u->left) {
            pa[u->left] = u;
            dfs(u->left, i + 1);
        }

        if (u->right) {
            pa[u->right] = u;
            dfs(u->right, i + 1);
        }
    }

    TreeNode *lcaDeepestLeaves(TreeNode *root) {
        if (!root->left && !root->right) return root;
        dfs(root, 0);
        unordered_set < TreeNode * > t;
        while (true) {
            if (s.size() == 1) return *s.begin();
            t.clear();
            for (TreeNode *u: s)
                t.insert(pa[u]);
            s = t;
        }
        return NULL;
    }
};
