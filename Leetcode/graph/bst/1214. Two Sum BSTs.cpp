//
// Created by Hoang, Quang on 2019-11-21.
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

    void dfs(TreeNode* u, vector<int>& a) {
        if (!u) return;
        dfs(u->left, a);
        a.push_back(u->val);
        dfs(u->right, a);
    }

    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<int> a, b;
        dfs(root1, a);
        dfs(root2, b);
        int i = 0, j = b.size() - 1;
        while (i < a.size() && j >= 0) {
            if (a[i] + b[j] == target) return true;
            if (a[i] + b[j] < target) i++;
            if (a[i] + b[j] > target) j--;
        }
        return false;
    }
};