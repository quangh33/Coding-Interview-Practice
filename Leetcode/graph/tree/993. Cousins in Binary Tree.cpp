//
// Created by Hoang, Quang on 2019-08-12.
//

// https://leetcode.com/problems/cousins-in-binary-tree/


#include <MacTypes.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int parent[101];
    int level[101];

    void dfs(TreeNode *u, int p) {
        if (u == NULL) return;
        parent[u->val] = p;
        level[u->val] = level[p] + 1;
        dfs(u->left, u->val);
        dfs(u->right, u->val);
    }

    bool isCousins(TreeNode *root, int x, int y) {
        parent[0] = -1;
        level[0] = -1;
        dfs(root, 0);
        return (parent[x] != parent[y] && level[x] == level[y]);
    }
};