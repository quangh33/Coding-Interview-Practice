//
// Created by Hoang, Quang on 2019-08-10.
//

#include <vector>

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
    int maxDepth(Node* root) {
        if (root == NULL) return 0;
        if (root->children.size() == 0) return 1;
        int maxDep = 0;
        for(int i = 0; i < root->children.size(); i++) {
            Node* child = root->children[i];
            maxDep = max(maxDep, maxDepth(child));
        }
        return maxDep+1;
    }
};