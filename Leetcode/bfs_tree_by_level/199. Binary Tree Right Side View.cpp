//
// Created by Hoang, Quang on 2019-08-12.
//

// https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int currentSize = q.size();
            int lastNodeOfCurrentLevel = -1;

            for(int i = 0; i < currentSize; i++) {
                TreeNode* u = q.front();
                q.pop();
                lastNodeOfCurrentLevel = u->val;

                if (u->left != NULL) q.push(u->left);
                if (u->right != NULL) q.push(u->right);
            }
            res.push_back(lastNodeOfCurrentLevel);
        }
        return res;
    }
};