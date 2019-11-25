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
    vector<int> a;
    vector<vector<int>> pos, ma;

    void dfs(TreeNode* u) {
        if (!u) return;
        dfs(u->left);
        a.push_back(u->val);
        dfs(u->right);
    }

    TreeNode* build(int l, int r) {
        if (l > r) return NULL;
        TreeNode* u = new TreeNode(ma[l][r]);
        int mid = pos[l][r];
        u->left = build(l, mid - 1);
        u->right = build(mid + 1, r);
        return u;
    }

    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        dfs(root);
        for(int i : a ) cout<<i<<" ";
        a.push_back(val);
        int n = a.size();
        ma = vector<vector<int>>(n, vector<int>(n));
        pos = ma;

        for(int i = 0; i < n; i++) {
            ma[i][i] = a[i];
            pos[i][i] = i;
        }

        for(int len = 2; len <= n; len++) {
            for(int i = 0; i < n-len+1; i++) {
                int j = i + len - 1;
                if (ma[i][j-1] > a[j]) {
                    ma[i][j] = ma[i][j-1];
                    pos[i][j] = pos[i][j-1];
                } else {
                    ma[i][j] = a[j];
                    pos[i][j]= j;
                }
            }
        }

        return build(0, n-1);
    }
};