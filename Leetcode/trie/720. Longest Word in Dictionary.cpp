//
// Created by Hoang, Quang on 2019-11-25.
//

class Solution {
public:
    struct node {
        vector<node *> child;
        bool end;
        string value;

        node() : end(false), value(""), child(vector<node *>(26, NULL)) {};
    };

    node *root = new node();
    int maxLen = 0;
    string res = "";

    void add(string s, node *root) {
        for (char c: s) {
            int i = c - 'a';
            if (!root->child[i]) root->child[i] = new node();
            root = root->child[i];
        }
        root->end = true;
        root->value = s;
    }

    void dfs(node *u, int len) {
        if (u != root) {
            if (len > maxLen) {
                maxLen = len;
                res = u->value;
            }
        }
        for (int i = 0; i < 26; i++)
            if (u->child[i] && u->child[i]->end)
                dfs(u->child[i], len + 1);
    }

    string longestWord(vector <string> &words) {
        root = new node();
        for (string word: words) add(word, root);
        dfs(root, 0);
        return res;
    }
};