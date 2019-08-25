#include<iostream>
#include<vector>
#include<queue>
#include <unordered_map>
#include <cstring>

using namespace std;

vector<int> sortArrayByParityII(vector<int>& A) {
    int odd = 0;
    int even = 1;
    for(int i = 0; i < A.size(); i++) {
        if (A[i] % 2 == 0) {
            swap(A[i], A[odd]);
            odd+=2;
        }
    }
    return A;
}

int main() {
    vector<int> a = { 4, 2, 5, 7 };
    sortArrayByParityII(a);
    return 0;
}