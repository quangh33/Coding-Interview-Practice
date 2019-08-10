#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <string>
#include <queue>
#include <array>
#include <unordered_map>
#include <stack>

using namespace std;

int n;
vector<int> children[5001];

int maxDepth(int u) {
    if (children[u].size() == 0) return 1;
    int maxDep = 0;
    for(int i = 0; i < children[u].size(); i++) {
        int v = children[u][i];
        maxDep = max(maxDep, maxDepth(v));
    }
    return maxDep+1;
}

int main() {
    cin>>n;
    for(int i = 1; i < n; i++) {
        int u;
        cin>>u;
        children[u].push_back(i);
    }
    cout<<maxDepth(0);
    return 0;
}