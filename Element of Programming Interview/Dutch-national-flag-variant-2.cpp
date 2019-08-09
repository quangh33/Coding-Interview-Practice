/*
 * Assuming that keys take one of 4 values, reorder the array so that all objects with the same key appear together.
 * The order of the subarrays is not important.
 * Use 0(1) additional space and 0(n) time.
 */

/*
 * The idea is to maintain a boundaryIndex such that a[0], .., a[boundaryIndex-1] == pivot
 * by iterate the array:
 *  if the current item == pivot:
 *      swap(item, a[boundaryIndex]
 *      boundaryIndex++;
 */
#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int> &a) {
    int n = a.size();
    int boundaryIndex = 0;
    while (boundaryIndex < n) {
        int pivot = a[boundaryIndex];
        for(int i = boundaryIndex; i < n; i++) {
            if (a[i] == pivot) swap(a[i], a[boundaryIndex++]);
        }
    }
}

int main() {
    // vector<int> a = { 1, 2, 2, 1, 3, 3, 4, 4, 2, 1, 1, 2, 3, 1};
    vector<int> a = { 1, 2, 1, 2, 1, 2, 3 };
    sort(a);
    for(int i : a) cout<<i<<" ";
}

