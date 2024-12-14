#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
void merge(T* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    T leftArr[n1];
    T rightArr[n2];

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
  
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] >= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
  
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
  
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

template <class T>
void mergeSort(T* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
const int MAX_SIZE = int(10e5);
int arr[MAX_SIZE]{};

int main() {
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    mergeSort<int>(arr, 0, N - 1);
    
    for(int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }
    
    return 0;
}
