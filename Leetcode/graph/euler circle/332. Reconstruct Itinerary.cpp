class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> a; 
    vector<string> res;
    
    void dfs(string u) {
        while (!a[u].empty()) {
            string v = a[u].top();
            a[u].pop();
            dfs(v);
        }
        res.push_back(u);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto ticket: tickets) {
            string u = ticket[0];
            string v = ticket[1];
            a[u].push(v);
        }
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};