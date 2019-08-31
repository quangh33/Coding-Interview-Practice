#include<iostream>
#include<vector>
#include<queue>
#include <unordered_map>
#include <cstring>
#include <set>
#include <map>

using namespace std;

int minimumTotal(vector<vector<int>> &a) {
    int n = a.size();
    if (n == 0) return 0;
    int fx[n];
    fx[0] = a[0][0];

    for (int i = 1; i < n; i++) {
        for (int j = a[i].size() - 1; j >= 0; j--) {
            if (j != a[i].size() - 1) fx[j] = fx[j] + a[i][j];
            if (j > 0) {
                if (j != a[i].size() - 1) fx[j] = min(fx[j], fx[j-1] + a[i][j]);
                else fx[j] = fx[j-1] + a[i][j];
            }
        }
    }
    int res = INT_MAX;
    for (int j = 0; j < a[n - 1].size(); j++) res = min(res, fx[j]);
    return res;
}

int main() {
    vector<vector<int>> a = {
            {2},
            {3, 4},
            {6, 5, 7},
            {4, 1, 8, 3}
    };
    cout<<minimumTotal(a);

    return 0;
}