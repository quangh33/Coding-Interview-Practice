/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> adj[501];
    
    void dfs(TreeNode* u) {
        if (u->left != NULL) {
            adj[u->val].push_back(u->left->val);
            adj[u->left->val].push_back(u->val);
            dfs(u->left);
        }    
        
        if (u->right != NULL) {
            adj[u->val].push_back(u->right->val);
            adj[u->right->val].push_back(u->val);
            dfs(u->right);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        dfs(root);
        queue<int> q;
        q.push(target->val);
        int dis[501];
        memset(dis, -1, sizeof(dis));
        dis[target->val] = 0;
        
        vector<int> res;
        
        if (K == 0) {
            res.push_back(target->val);
            return res;
        }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for(int v: adj[u]) {
                if (dis[v] == -1 && dis[u] + 1 <= K) {
                    dis[v] = dis[u] + 1;
                    if (dis[v] == K) res.push_back(v);
                    q.push(v);
                }
            }
        }
        return res;
    }
};