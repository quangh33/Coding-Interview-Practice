class Trie {
public:
    struct node {
        bool end;
        vector<node *> child;

        node() : end(false), child(vector<node *>(26, NULL)) {};
    };

    node *root;

    /** Initialize your data structure here. */
    Trie() {
        root = new node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        node *cur = root;
        for (char c: word) {
            if (!cur->child[c - 'a']) cur->child[c - 'a'] = new node();
            cur = cur->child[c - 'a'];
        }
        cur->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        node *cur = root;
        for (char c: word) {
            if (!cur->child[c - 'a']) return false;
            cur = cur->child[c - 'a'];
        }
        return cur->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node *cur = root;
        for (char c: prefix) {
            if (!cur->child[c - 'a']) return false;
            cur = cur->child[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
