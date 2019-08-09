/*
 Implement a function which takes as input an array and a key and updates the array so that all occurrences of
 the input key have been removed and the remaining elements have been shifted left to fill the emptied indices.
 Return the number of remaining elements. There are no requirements as to the values stored beyond the last valid element.
 */
#include <iostream>
#include <vector>

using namespace std;


int dedup(vector<int> a, int k) {
    int firstFreePos = 0;
    for(int i = 0; i < a.size(); i++) {
        if (a[i] != k) {
            a[firstFreePos++] = a[i];
        }
    }
    int res = firstFreePos;
    for(int i = firstFreePos; i < a.size(); i++) a[i]=0;
    for(int i = 0; i < a.size(); i++) cout<<a[i]<<" ";
    cout<<endl;
    return res;
}

int main() {
    vector<int> a = {2, 1, 3, 4, 1, 1, 7};
    cout<<dedup(a, 1);
    return 0;
}