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
    void dfs(TreeNode *u, vector<int> &a) {
        if (!u) return;
        dfs(u->left, a);
        a.push_back(u->val);
        dfs(u->right, a);
    }

    vector<int> merge(vector<int> a, vector<int> b) {
        int i = 0;
        int j = 0;
        int n = a.size();
        int m = b.size();
        vector<int> res;
        while (i < n && j < m) {
            if (a[i] < b[j]) {
                res.push_back(a[i]);
                i++;
            } else {
                res.push_back(b[j]);
                j++;
            }
        }

        while (i < n) res.push_back(a[i++]);
        while (j < m) res.push_back(b[j++]);
        return res;
    }

    vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
        vector<int> a, b;
        dfs(root1, a);
        dfs(root2, b);

        return merge(a, b);
    }
};