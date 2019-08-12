//
// Created by Hoang, Quang on 2019-08-12.
//

// https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
    int dfs(TreeNode *u) {
        if (u == NULL) return INT_MAX;
        if (u->left == NULL && u->right == NULL) return 1;
        return min(dfs(u->left), dfs(u->right)) + 1;
    }

    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        return dfs(root);
    }
};