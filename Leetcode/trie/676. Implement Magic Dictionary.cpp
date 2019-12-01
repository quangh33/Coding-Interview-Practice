//
// Created by Hoang, Quang on 2019-11-25.
//

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    struct node {
        bool end;
        node *child[26];
    };

    node *root;

    node *create() {
        node *temp = new node();
        temp->end = false;
        memset(temp->child, NULL, sizeof(temp->child));
        return temp;
    }

    void add(string s) {
        node *cur = root;
        for (char c: s) {
            if (cur->child[c - 'a'] == NULL) cur->child[c - 'a'] = create();
            cur = cur->child[c - 'a'];
        }
        cur->end = true;
    }

    MagicDictionary() {
        root = create();
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector <string> dict) {
        for (string s: dict)
            add(s);
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */

    bool found(string s) {
        node *cur = root;
        for (char c: s) {
            cur = cur->child[c - 'a'];
            if (cur == NULL) return false;
        }
        return cur->end;
    }

    bool search(string word) {
        node *cur = root;
        for (int i = 0; i < word.size(); i++) {
            string s = word;
            for (char c = 'a'; c <= 'z'; c++) {
                s[i] = c;
                if (s != word)
                    if (found(s)) {
                        cout << s << endl;
                        return true;
                    }
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */