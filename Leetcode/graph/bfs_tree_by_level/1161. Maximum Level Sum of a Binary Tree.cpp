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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        int res = 1;
        int maxSum = INT_MIN;

        while (!q.empty()) {
            level++;
            int currentSize = q.size();
            int sum = 0;
            for(int i = 0; i < currentSize; i++) {
                TreeNode* u = q.front();
                q.pop();
                sum += u->val;
                if (u->left) q.push(u->left);
                if (u->right) q.push(u->right);
            }
            if (maxSum < sum) {
                maxSum = sum;
                res = level;
            }
        }
        return res;
    }
};