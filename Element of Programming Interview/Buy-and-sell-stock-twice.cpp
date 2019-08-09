/*
 6.7 - Page 71

 Write a program that computes the maximum profit that can be made by buying and selling a share at most twice.
 The second buy must be made on another date after the first sale
 */


/*
 Idea:
 - calculate f[i]: max profit can be made by buying & selling once by day i inclusive
 - calculate g[i]: max profit can be made by buying & selling on day i or after
 - result = max(f[i] + g[i+1])

 We can calculate f[i] by maintaining a minSoFar value = min stock price by day i inclusive
 iterate the array:
    f[i] = min(f[i-1], a[i] - minSoFar)
    minSoFar = min(minSoFar, a[i])

 g[i] is calculated by the same mechanism
 */


#include <iostream>
#include <vector>

using namespace std;

int sellAndBuyTwice(vector<int> a) {
    int minSoFar = a[0];
    int n = a.size();
    int f[n];
    int g[n];
    f[0] = 0;
    for (int i = 1; i < n; i++) {
        f[i] = max(f[i - 1], a[i] - minSoFar);
        minSoFar = min(minSoFar, a[i]);
    }

    g[n - 1] = 0;
    int maxSoFar = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        g[i] = max(g[i + 1], maxSoFar - a[i]);
        maxSoFar = max(maxSoFar, a[i]);
    }

    int res = 0;
    for (int i = 1; i < n; i++) res = max(res, g[i] + f[i - 1]);
    return res;
}

int main() {
    // vector<int> a = {12, 11, 13, 9, 12, 8, 14, 13, 15};
    vector<int> a = {12, 11, 10, 9, 8, 7, 6, 5, 8};
    cout << sellAndBuyTwice(a);
    return 0;
}