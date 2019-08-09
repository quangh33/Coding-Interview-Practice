/*
 Write a program which takes as input a sorted array and updates it so that all duplicates
 have been removed and the remaining elements have been shifted left to fill the emptied indices.
 Return the number of valid elements. Many languages have library functions for performing this operation—you
 cannot use these functions.

    Hint: There is an 0(n) time and 0(1) space solution.
 */


/*
 Idea:
 iterate through the array and maintain a firstFreeIndex value which is the first index that we should shift
 the remain item to.
 */
#include <iostream>
#include <vector>

using namespace std;


int dedup(vector<int> a) {
    int firstFreeIndex = 1;
    for(int i = 1; i < a.size(); i++) {
        if (a[i] != a[i-1]) {
            a[firstFreeIndex++] = a[i];
        }
    }
    int res = firstFreeIndex;
    for(int i = firstFreeIndex; i < a.size(); i++) a[i] = 0;
    for(int i: a) cout<<i<<" ";
    cout<<endl;
    return res;
}

int main() {
    // vector<int> a = {1, 2, 2, 3, 3, 3, 4, 4, 7, 8, 8, 13};
    vector<int> a = {1, 1, 2};
    cout<<dedup(a);
    return 0;
}