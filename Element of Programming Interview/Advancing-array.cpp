/*
 * Write a program which takes an array of n integers, where A[i] denotes the maximum you can advance from index i,
 * and returns whether it is possible to advance to the last index starting from the beginning of the array.
 * also return minimum step need to take.
 */
#include <iostream>
#include <vector>

using namespace std;

bool reach(vector<int> a) {
    int furthest = 0;
    for(int i = 0; i <= furthest; i++) {
        furthest = max(furthest, i+a[i]);
    }
    return furthest >= a.size()-1;
}

int countMinStep(vector<int> a) {
    int step = 0;
    int currentPosition = 0;
    while (true) {
        int furthest = currentPosition + a[currentPosition];
        if (furthest >= a.size()) break;
        int nextStep = furthest;
        for(int i = currentPosition; i < furthest; i++) {
            if (i + a[i] > furthest) {
                nextStep = i;
                furthest = a[i] + i;
            }
        }
        currentPosition = nextStep;
        step++;
    }
    return step;
}
int main() {
    vector<int> a = {3, 3, 1, 0, 2, 0, 1};
    cout<<reach(a)<<endl;
    cout<<countMinStep(a);
    return 0;
}