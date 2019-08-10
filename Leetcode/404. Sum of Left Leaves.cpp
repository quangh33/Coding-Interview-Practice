//
// Created by Hoang, Quang on 2019-08-10.
//

#include <MacTypes.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

class Solution {
public:
    void dfs(TreeNode *u, bool isLeft, int &sum) {
        if (u == NULL) return;
        if (u->left == NULL && u->right == NULL) {
            if (isLeft) sum = sum + u->val;
            return;
        }
        dfs(u->left, true, sum);
        dfs(u->right, false, sum);
    }

    int sumOfLeftLeaves(TreeNode *root) {
        int res = 0;
        if (root == NULL) return 0;
        dfs(root, false, res);
        return res;
    }
};