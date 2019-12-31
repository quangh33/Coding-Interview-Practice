#include <iostream>
#include <vector>

using namespace std;

void plusOne(vector<int> &a) {
    int n = a.size();
    int carryOut = 1;
    for(int i = n-1; i>=0; i--) {
        int sum = a[i] + carryOut;
        if (sum > 9) {
            a[i] = sum%10;
            carryOut = 1;
        } else {
            a[i] = sum;
            carryOut = 0;
        }
        if (carryOut == 0) break;
    }
    if (carryOut == 1) a.insert(a.begin(), 1);
}

int main() {
    vector<int> a = {1, 2, 9};
    plusOne(a);
    for(int i : a) cout<<i<<" ";
    return 0;
}