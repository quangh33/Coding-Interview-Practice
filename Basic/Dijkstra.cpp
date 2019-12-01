#include<vector>
#include<queue>
#include<bits

/*
    O(n log n + m log n) = O(m log n)
*/

using namespace std;

typedef pair<int, int> ii;

int dijstra(vector<vector<int>>& edges, int N, int Source) {
        vector<ii> a[N+1];
        for(auto e: edges) {
            int u = e[0], v = e[1], w = e[2];
            a[u].push_back(ii(v, w));
        }
        priority_queue<ii, vector<ii>, greater<ii> > q;
        int fx[N+1];
        for(int i = 1; i <= N; i++) fx[i] = INT_MAX;
        fx[Source] = 0;
        q.push(ii(0, Source));

        while (q.size()) {
            int u = q.top().second;
            q.pop();
            for(auto pair: a[u]) {
                int v = pair.first;
                int w = pair.second;
                if (fx[v] > fx[u] + w) {
                    fx[v] = fx[u] + w;
                    q.push(ii(fx[v], v));
                }
            }
        }
  }