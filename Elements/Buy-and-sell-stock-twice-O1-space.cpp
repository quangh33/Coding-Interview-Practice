/*
 6.7 - Page 71

 Write a program that computes the maximum profit that can be made by buying and selling a share at most twice.
 The second buy must be made on another date after the first sale

 */


/*
 O(n) time, O(1) space

 Idea:
    iterate through the price array and calculate:
        - minSoFar = min(a[i])
        - maxProfitAfterFirstSell = max(a[i] - minSoFar)
        - maxProfitAfterSecondBuy = max(maxProfitAfterFirstSell - a[i]);
        - maxProfitAfterSecondSell = max(maxProfitAfterSecondBuy + a[i]);
 */


#include <iostream>
#include <vector>

using namespace std;

int sellAndBuyTwice(vector<int> a) {
    int n = a.size();
    if (n == 0) return 0;
    int minPrice = a[0];
    int maxProfitAfterFirstSell = 0;
    int maxProfitAfterSecondBuy = INT_MIN;
    int maxProfitAfterSecondSell = 0;

    for (int i = 1; i < n; i++) {
        maxProfitAfterSecondBuy = max(maxProfitAfterSecondBuy, maxProfitAfterFirstSell - a[i]);
        maxProfitAfterSecondSell = max(maxProfitAfterSecondSell, maxProfitAfterSecondBuy + a[i]);
        maxProfitAfterFirstSell = max(maxProfitAfterFirstSell, a[i] - minPrice);
        minPrice = min(minPrice, a[i]);
    }
    return max(maxProfitAfterSecondSell, maxProfitAfterFirstSell);
}

int main() {
    // vector<int> a = {12, 11, 13, 9, 12, 8, 14, 13, 15};
    // vector<int> a = {12, 11, 10, 9, 8, 7, 6, 5, 8};
    vector<int> a = {1, 2, 3, 4, 5};
    cout << sellAndBuyTwice(a);
    return 0;
}