//
// Created by Hoang, Quang on 2019-08-11.
//

// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> currentLevel;
            int currentSize = q.size();
            for(int i = 0; i < currentSize; i++) {
                Node* u = q.front();
                q.pop();
                currentLevel.push_back(u->val);

                for(Node* v: u->children) q.push(v);
            }
            res.push_back(currentLevel);
        }
        return res;
    }
};

