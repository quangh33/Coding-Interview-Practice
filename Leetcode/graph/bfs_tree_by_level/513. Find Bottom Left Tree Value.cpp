//
// Created by Hoang, Quang on 2019-08-12.
//

// https://leetcode.com/problems/find-bottom-left-tree-value/

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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currentSize = q.size();
            vector<int> currentLevel;

            bool isLastLevel = true;

            for(int i = 0; i < currentSize; i++) {
                TreeNode* u = q.front();
                q.pop();

                currentLevel.push_back(u->val);
                if (u->left != NULL) {
                    isLastLevel = false;
                    q.push(u->left);
                }
                if (u->right != NULL) {
                    isLastLevel = false;
                    q.push(u->right);
                }
            }

            if (isLastLevel) return currentLevel[0];
        }
        return 0;
    }
};