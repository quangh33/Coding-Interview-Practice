//
// Created by Hoang, Quang on 2019-08-10.
//

// https://leetcode.com/problems/same-tree/

#include <MacTypes.h>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(TreeNode *u, vector<int> &nodes) {
        if (u == NULL) {
            nodes.push_back(-1);
            return;
        }
        nodes.push_back(u->val);
        dfs(u->left, nodes);
        dfs(u->right, nodes);
    }

    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) return true;
        if (root1 == NULL || root2 == NULL) return false;
        vector<int> a, b;
        dfs(root1, a);
        dfs(root2, b);
        if (a.size() != b.size()) return false;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
};

