//
// Created by Hoang, Quang on 2019-08-12.
//

// https://leetcode.com/problems/symmetric-tree/

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
    bool isSymmetricArray(vector<int> a) {
        int n = a.size();
        for(int i = 0; i < n / 2; i++) {
            if (a[i] != a[n-i-1]) return false;
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currentSize = q.size();
            vector<int> currentLevel;

            for(int i = 0; i < currentSize; i++) {
                TreeNode* u = q.front();
                q.pop();
                if (u != NULL) {
                    currentLevel.push_back(u->val);
                    q.push(u->left);
                    q.push(u->right);
                } else {
                    currentLevel.push_back(-1);
                }
            }
            if (!isSymmetricArray(currentLevel)) return false;
        }
        return true;
    }
};

