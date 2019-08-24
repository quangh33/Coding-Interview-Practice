#include<iostream>
#include<vector>
#include<queue>
#include <unordered_map>
#include <cstring>

using namespace std;


vector<vector<int>> res;

void build(int i, vector<int> a, vector<bool> visited, vector<int> per) {
    if (i == a.size()) {
        res.push_back(per);
        return;
    }
    for(int j = 0; j < a.size(); j++) {
        if (visited[j]) continue;
        // when a number has the same value with its previous, we can use this number only if his previous is used
        if (j > 0 && a[j] == a[j-1] && !visited[j-1]) continue;
        visited[j] = true;
        per.push_back(a[j]);
        build(i+1, a, visited, per);
        per.pop_back();
        visited[j] = false;
    }
}

vector<vector<int>> permuteUnique(vector<int>& a) {
    sort(a.begin(), a.end());
    vector<bool> visited(a.size(), false);
    vector<int> per = {};
    build(0, a, visited, per);
    return res;
}

int jump(vector<int>& a) {
    int step = 0;
    int i = 0;
    int n = a.size();
    int furthest = 0;
    while (true) {
        if (furthest >= n-1) break;
        int nextStep;
        int temp = furthest;
        for(int j = i; j <= temp; j++) {
            if (j + a[j] > furthest) {
                nextStep = j;
                furthest = j + a[j];
            }
        }
        i = nextStep;
        step++;
    }
    return step;
}

int main() {
    vector<int> a = { 2,3,1,1,4 };
    cout<<jump(a);
    return 0;
}