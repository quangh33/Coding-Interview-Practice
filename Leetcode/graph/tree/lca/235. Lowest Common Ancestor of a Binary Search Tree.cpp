//
// Created by Hoang, Quang on 2020-01-06.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pVal = p->val;
        int qVal = q->val;
        if (pVal < root->val && qVal < root->val) return lowestCommonAncestor(root->left, p, q);
        if (pVal > root->val && qVal > root->val) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};