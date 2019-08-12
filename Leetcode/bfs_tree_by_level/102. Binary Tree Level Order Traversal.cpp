//
// Created by Hoang, Quang on 2019-08-12.
//


// https://leetcode.com/problems/binary-tree-level-order-traversal/

#include <MacTypes.h>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currentSize = q.size();
            vector<int> currentLevel;
            for(int i = 0; i < currentSize; i++) {
                TreeNode* u = q.front();
                q.pop();

                currentLevel.push_back(u->val);
                if (u->left != NULL) {
                    q.push(u->left);
                }
                if (u->right != NULL) {
                    q.push(u->right);
                }
            }

            res.push_back(currentLevel);
        }
        return res;
    }
};

