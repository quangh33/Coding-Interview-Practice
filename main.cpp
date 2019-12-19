#include<iostream>
#include<vector>
#include<queue>
#include <unordered_map>
#include <cstring>
#include <unordered_set>
#include <map>

using namespace std;

int main() {
    map<int, int> m;
    m[10] = 9;
    m[2] = 1;
    m[4] = 2;
    cout<<m.begin()->first;
}