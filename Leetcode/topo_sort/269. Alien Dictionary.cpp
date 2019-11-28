class Solution {
public:
    vector<int> a[26];
    bool visited[26];
    bool inDfs[26];
    int q[26];
    int id;
    bool hasCircle;
    
    void buildEdge(string s, string t) {
        int n = min(s.size(), t.size());
        for(int i = 0; i < n; i++) 
            if (s[i] != t[i]) {
                int u = s[i] - 'a';
                int v = t[i] - 'a';
                a[u].push_back(v);
                return;
            }
    }
    
    void dfs(int u) {
        visited[u] = true;
        inDfs[u] = true;
        
        for(int i = 0; i < a[u].size(); i++) {
            int v = a[u][i];
            if (!visited[v]) {
                dfs(v);
            } else if (inDfs[v]) {
                hasCircle = true;
                return;
            }
        }
        q[id--] = u;
        inDfs[u] = false;
    }
    
    string alienOrder(vector<string>& words) {
        hasCircle = false;
        string res = "";
        if (words.size() == 0) return res;
        
        unordered_set<char> dic;
        for(int i = 0; i < words.size(); i++) {
            if (i < words.size() - 1) buildEdge(words[i], words[i+1]);
            for(char c: words[i]) dic.insert(c);
        }
        id = dic.size() - 1;
        memset(visited, false, sizeof(visited));
        memset(inDfs, false, sizeof(inDfs));
        
        for(auto c: dic)
            if (!visited[c-'a']) dfs(c-'a');
        
        if (hasCircle) return res;
        for(int i = 0; i < dic.size(); i++) {   
            res = res + char(q[i] + int('a'));
        }
        return res;
    }
};