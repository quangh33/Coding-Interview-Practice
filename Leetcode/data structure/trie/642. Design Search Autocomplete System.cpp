class AutocompleteSystem {
public:
    struct node {
        vector<node*> child;
        int times;
        string sentence;
        node(): times(0), sentence(""), child(vector<node*>(27, NULL)) {};
    };
    
    typedef pair<int, string> IS;
    
    class ComparisonClass {
        public: 
            bool operator() (IS& a, IS& b) {
                return a.first > b.first || (a.first == b.first && a.second < b.second);
            }
    };
    

    priority_queue<IS, vector<IS>, ComparisonClass> q;
    
    node* root;
    
    void add(string s, int times) {
        node* cur = root;
        for(char c: s) {
            int i = c == ' ' ? 26 : c - 'a';
            if (!cur->child[i]) cur->child[i] = new node();
            cur = cur->child[i];
        }
        cur->times += times;
        cur->sentence = s;
    }
    
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new node();
        for(int i = 0; i < sentences.size(); i++) add(sentences[i], times[i]);
    }
    
    void dfs(node* u, string s) {
        if (u->times > 0) {
            q.push(make_pair(u->times, s));
            if (q.size() > 3) q.pop();
        }
        
        for(char c = 'a'; c <= 'z'; c++) {
            int i = c - 'a';
            if (u->child[i]) dfs(u->child[i], s + c);
        }
        if (u->child[26]) dfs(u->child[26], s + ' ');     
    }
    
    void lookup(string s) {
        q = priority_queue<IS, vector<IS>, ComparisonClass>();
        node* cur = root;
        for(char c: s) {
            int i = c == ' ' ? 26: c - 'a';
            if (!cur->child[i]) return;
            cur = cur->child[i];
        }
        dfs(cur, s);
    }
    
    string current = "";
    vector<string> input(char c) {
        vector<string> res;
        if (c == '#') {
            add(current, 1);
            current = "";
        } else {
            current += c;
            lookup(current);
            while (!q.empty()) {
                res.push_back(q.top().second);
                q.pop();
            };
            reverse(res.begin(), res.end());
        }
        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */