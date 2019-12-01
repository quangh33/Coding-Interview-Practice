//
// Created by Hoang, Quang on 2019-11-25.
//
class MapSum {
public:
    /** Initialize your data structure here. */

    unordered_map<string, int> value;

    struct node {
        bool end;
        node *child[26];
        int v;
    };

    node *root;

    node *create() {
        node *temp = new node();
        temp->end = false;
        memset(temp->child, NULL, sizeof(temp->child));
        temp->v = 0;
        return temp;
    }

    MapSum() {
        root = create();
    }

    void insert(string key, int val) {
        int delta = val - value[key];
        value[key] = val;

        node *cur = root;
        for (char c: key) {
            if (cur->child[c - 'a'] == NULL) cur->child[c - 'a'] = create();
            cur = cur->child[c - 'a'];
            cur->v += delta;
        }
        cur->end = true;
    }

    int sum(string prefix) {
        node *cur = root;
        for (char c: prefix) {
            cur = cur->child[c - 'a'];
            if (cur == NULL) return 0;
        }
        return cur->v;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
