//
// Created by Hoang, Quang on 2019-12-15.
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
class Solution {
public:

    Node *res;
    Node *prev;
    Node *target;

    void dfs(Node *u) {
        if (!u) return;
        dfs(u->left);
        if (prev)
            if (prev == target) {
                res = u;
                prev = u;
                return;
            }
        prev = u;
        dfs(u->right);
    }

    Node *inorderSuccessor(Node *node) {
        if (node->right) {
            node = node->right;
            while (node->left) node = node->left;
            return node;
        }

        while (node->parent && node == node->parent->right) node = node->parent;
        return node->parent;
    }
};