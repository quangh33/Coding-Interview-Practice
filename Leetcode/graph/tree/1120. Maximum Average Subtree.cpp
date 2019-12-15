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
    double res;

    void dfs(TreeNode *u, double &sum, int &count) {
        double s = u->val;
        int c = 1;
        if (!u->left && !u->right) {
            sum = s;
            count = c;
            res = max(res, s / c);
            return;
        }
        if (u->left) {
            double sumLeft;
            int countLeft;
            dfs(u->left, sumLeft, countLeft);
            s += sumLeft;
            c += countLeft;
        }
        if (u->right) {
            double sumRight;
            int countRight;
            dfs(u->right, sumRight, countRight);
            s += sumRight;
            c += countRight;
        }
        sum = s;
        count = c;
        res = max(res, s / c);
        return;
    }

    double maximumAverageSubtree(TreeNode *root) {
        double x;
        int y;
        res = 0.0;
        dfs(root, x, y);
        return res;
    }
};
