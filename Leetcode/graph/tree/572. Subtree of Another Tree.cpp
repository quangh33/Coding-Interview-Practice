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
    bool equal(TreeNode *u, TreeNode *v) {
        if (!u && !v) return true;
        if (!u || !v) return false;
        return u->val == v->val && equal(u->left, v->left) && equal(u->right, v->right);
    }

    bool isSubtree(TreeNode *s, TreeNode *t) {
        return equal(s, t) ||
               (s && isSubtree(s->left, t)) ||
               (s && isSubtree(s->right, t));
    }
};