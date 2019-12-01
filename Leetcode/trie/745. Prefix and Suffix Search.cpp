//
// Created by Hoang, Quang on 2019-11-25.
//

class WordFilter {
    struct Node {
        bool end;
        int maxIndex;
        vector<Node *> child;

        Node() : end(false), maxIndex(0), child(vector<Node *>(27, NULL)) {};
    };

    Node *root;
public:

    void addWord(string word, int index) {
        Node *cur = root;
        for (char c: word) {
            int i = c == '#' ? 26 : (c - 'a');
            if (!cur->child[i]) cur->child[i] = new Node();
            cur = cur->child[i];
            cur->maxIndex = max(cur->maxIndex, index);
        }
        cur->end = true;
    }

    WordFilter(vector <string> &words) {
        root = new Node();
        int index = -1;
        for (string word: words) {
            index++;
            for (int i = word.size() - 1; i >= 0; i--) {
                string s = word.substr(i, word.size() - i + 1) + "#" + word;
                addWord(s, index);
            }
            addWord("#" + word, index);
        }
    }

    int f(string prefix, string suffix) {
        string s = suffix + "#" + prefix;
        if (s == "#") return 0;
        Node *cur = root;
        for (char c: s) {
            int i = c == '#' ? 26 : (c - 'a');
            if (!cur->child[i]) return -1;
            cur = cur->child[i];
        }
        return cur->maxIndex;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */