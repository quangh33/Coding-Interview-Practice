//
// Created by Hoang, Quang on 2019-08-12.
//

// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root == NULL) return res;

        q.push(root);
        while (!q.empty()) {
            int currentSize = q.size();
            vector<int> currentLevel;

            for(int i = 0; i < currentSize; i++) {
                TreeNode* u = q.front();
                q.pop();
                currentLevel.push_back(u->val);
                if (u->left != NULL) q.push(u->left);
                if (u->right != NULL) q.push(u->right);
            }
            res.push_back(currentLevel);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
