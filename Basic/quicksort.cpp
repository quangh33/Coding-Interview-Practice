#include<iostream>

using namespace std;

int partition(int a[], int low, int high) {
    int pivotIndex = low + rand() % (high - low);
    int pivot = a[pivotIndex];
    swap(a[pivotIndex], a[high]);
    int index = low - 1;
    for(int i = low; i <= high; i++)
        if (a[i] < pivot) {
            swap(a[i], a[++index]);
        }
    swap(a[++index], a[high]);
    return index;    
}

void quicksort(int a[], int low, int high) {
    if (low < high) {
        int pivot = partition(a, low, high);
        quicksort(a, low, pivot - 1);
        quicksort(a, pivot + 1, high);
    }
}

int main() {
    int a[5] = { 5, 4, 3, 1, 2 };
    quicksort(a, 0, 4);
    for(int i : a) cout<<i<<" ";
}