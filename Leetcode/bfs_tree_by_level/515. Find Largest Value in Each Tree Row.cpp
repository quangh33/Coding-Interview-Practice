//
// Created by Hoang, Quang on 2019-08-12.
//

// https://leetcode.com/problems/find-largest-value-in-each-tree-row/


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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if (root == NULL) return res;

        q.push(root);
        while (!q.empty()) {
            int currentSize = q.size();
            int maxCurrentLevel = q.front()->val;

            for(int i = 0; i < currentSize; i++) {
                TreeNode* u = q.front();
                q.pop();

                maxCurrentLevel = max(maxCurrentLevel, u->val);
                if (u->left != NULL) q.push(u->left);
                if (u->right != NULL) q.push(u->right);
            }
            res.push_back(maxCurrentLevel);
        }
        return res;
    }
};