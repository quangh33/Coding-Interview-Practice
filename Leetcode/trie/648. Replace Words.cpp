//
// Created by Hoang, Quang on 2019-11-25.
//

class Solution {
public:
    struct node {
        bool end;
        node *child[26];
        int id;
    };

    node *create() {
        node *temp = new node();
        temp->end = false;
        memset(temp->child, NULL, sizeof(temp->child));
        return temp;
    }

    void insert(node *root, string s, int id) {
        for (char c: s) {
            if (root->child[c - 'a'] == NULL)
                root->child[c - 'a'] = create();
            root = root->child[c - 'a'];
        }
        root->id = id;
        root->end = true;
    }

    node *root;

    string replaceWords(vector <string> &dict, string sentence) {
        root = create();
        int i = 0;
        for (string s: dict) insert(root, s, i++);
        string word = "";
        string res = "";
        sentence = sentence + ' ';
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ') {
                if (word.size() != 0) {
                    node *cur = root;
                    bool ok = false;
                    for (char c: word) {
                        cur = cur->child[c - 'a'];
                        if (cur == NULL) break;
                        if (cur->end) {
                            res = res + dict[cur->id] + " ";
                            ok = true;
                            break;
                        }
                    }
                    if (!ok) res = res + word + " ";
                    word = "";
                }
            } else {
                word += sentence[i];
            }
        }
        res.erase(res.end() - 1, res.end());
        return res;
    }
};
