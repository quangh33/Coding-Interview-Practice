//
// Created by Hoang, Quang on 2019-11-25.
//

class Solution {
public:
    struct node {
        vector<node *> child;
        bool leaf;

        node() : leaf(false), child(vector<node *>(26, NULL)) {};
    };

    void add(node *root, string s) {
        for (char c: s) {
            if (!root->child[c - 'a']) root->child[c - 'a'] = new node();
            root = root->child[c - 'a'];
        }
        root->leaf = true;
    }

    vector <vector<int>> indexPairs(string text, vector <string> &words) {
        vector <vector<int>> res;
        node *root = new node();
        for (string word: words) add(root, word);
        int n = text.size();

        for (int i = 0; i < n; i++) {
            node *cur = root;
            for (int j = i; j < n; j++) {
                cur = cur->child[text[j] - 'a'];
                if (cur && cur->leaf) res.push_back({i, j});
                if (!cur) break;
            }
        }
        return res;
    }
};