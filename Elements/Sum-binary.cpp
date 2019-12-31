#include <iostream>
#include <vector>

using namespace std;

vector<int> sumBinary(vector<int> a, vector<int> b) {
    int n = a.size();
    int m = b.size();
    int carryOut = 0;
    vector<int> res(max(n,m), 0);
    int index = max(n,m);
    while (n >= 0 || m >= 0) {
        int x = n < 0 ? 0 : a[n];
        int y = m < 0 ? 0 : b[m];
        int sum = x+y+carryOut;
        res[index] = sum % 2;
        carryOut = sum > 1 ? 1 : 0;
        n--;
        m--;
        index--;
    }
    if (carryOut != 0) res.insert(res.begin(), 1);
    return res;
}

int main() {
    vector<int> a = {1, 0, 1};
    vector<int> b = {1, 1, 1, 1};
    vector<int> sum = sumBinary(a, b);
    for(int i : sum) cout<<i;
    return 0;
}