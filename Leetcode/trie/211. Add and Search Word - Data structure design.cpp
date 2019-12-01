//
// Created by Hoang, Quang on 2019-11-25.
//

class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct Node {
        vector<Node *> child;
        bool end;

        Node() : end(false), child(vector<Node *>(26, NULL)) {};
    };

    Node *root;

    void add(string s, Node *root) {
        for (char c: s) {
            int i = c - 'a';
            if (!root->child[i]) root->child[i] = new Node();
            root = root->child[i];
        }
        root->end = true;
    }

    WordDictionary() {
        root = new Node();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        add(word, root);
    }

    bool dfs(Node *u, int i, int n, string s) {
        if (i == n) {
            if (u->end) return true;
            else return false;
        }
        if (s[i] != '.') {
            if (u->child[s[i] - 'a']) return dfs(u->child[s[i] - 'a'], i + 1, n, s);
            else return false;
        } else {
            for (int c = 0; c < 26; c++)
                if (u->child[c])
                    if (dfs(u->child[c], i + 1, n, s)) return true;
        }
        return false;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(root, 0, word.size(), word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */