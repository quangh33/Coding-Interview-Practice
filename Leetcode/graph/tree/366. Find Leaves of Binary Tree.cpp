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
    vector<TreeNode *> nodes;
    unordered_map<TreeNode *, int> h;

    int dfs(TreeNode *u) {
        if (!u) return -1;
        nodes.push_back(u);

        if (!u->left && !u->right) {
            h[u] = 0;
            return 0;
        }
        h[u] = max(dfs(u->left) + 1, dfs(u->right) + 1);
        return h[u];
    }

    vector <vector<int>> findLeaves(TreeNode *root) {
        vector <vector<int>> res;
        if (!root) return res;
        dfs(root);
        int maxH = 0;
        for (auto node: nodes) {
            maxH = max(maxH, h[node]);
        }
        res = vector < vector < int >> (maxH + 1);
        for (auto node: nodes) {
            int height = h[node];
            res[height].push_back(node->val);
        }

        return res;
    }
};