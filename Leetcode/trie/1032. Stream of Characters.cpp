//
// Created by Hoang, Quang on 2019-11-25.
//

class StreamChecker {
public:
    struct Node {
        vector<Node *> child;
        bool end;

        Node() : end(false), child(vector<Node *>(26, NULL)) {};
    };

    Node *root;
    string s = "";

    void add(string s) {
        Node *u = root;
        for (int j = s.size() - 1; j >= 0; j--) {
            int i = s[j] - 'a';
            if (!u->child[i]) u->child[i] = new Node();
            u = u->child[i];
        }
        u->end = true;
    }

    StreamChecker(vector <string> &words) {
        root = new Node();
        for (string word: words)
            add(word);
        s = "";
    }

    bool query(char letter) {
        s = letter + s;
        if (s.size() > 2000) {
            s = s.substr(1, 2000);
        }

        Node *cur = root;
        for (char c: s) {
            int i = c - 'a';
            if (cur->child[i]) {
                cur = cur->child[i];
                if (cur->end) return true;
            } else return false;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */