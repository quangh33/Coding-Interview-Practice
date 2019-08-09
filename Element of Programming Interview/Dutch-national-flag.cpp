/*
 * given an array a, and k:
 * sort a such that: elements < a[k] come first, then elements == a[k], then elements > a[k]
 */


#include <iostream>
#include <vector>

using namespace std;

void reorder(vector<int> a, int k) {
    int pivot = a[k];
    int smaller = 0;
    int n = a.size();
    for(int i = 0; i < n; i++) {
        if (a[i] < pivot) swap(a[i], a[smaller++]);
    }

    int larger = n-1;
    for(int i = n-1; i >= 0; i--) {
        if (a[i] > pivot) swap(a[i], a[larger--]);
    }

    for(int i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }
}

int main() {
    vector<int> a = {4, 9, 3, 2, 4, 7, 4, 1, 0};
    reorder(a, 0);
    return 0;
}

