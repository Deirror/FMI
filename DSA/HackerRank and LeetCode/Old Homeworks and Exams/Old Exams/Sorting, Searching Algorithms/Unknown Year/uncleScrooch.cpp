#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int arr1[n1];
    int arr2[n2];
    
    for(int i  = 0; i < n1; i++) {
        arr1[i] = arr[i + left];
    }
  
    for(int i  = 0; i < n2; i++) {
        arr2[i] = arr[i + mid + 1];
    }
    
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if(arr1[i] <= arr2[j]) {
            arr[k++] = arr1[i++];
        } else {
            arr[k++] = arr2[j++];
        }
    }
    
    while(i < n1) {
        arr[k++] = arr1[i++];
    }
    
    while(j < n2) {
        arr[k++] = arr2[j++];
    }
}

void mergeSort(int* arr, int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int arr[int(1e6)];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    mergeSort(arr, 0 , n - 1);
    
    int counter = 0;
    for(int i = 0; i < n; i++) {
        k -= arr[i];
        if(k < 0) {
            break;
        }    
        counter++;
    }
    
    cout << counter;
       
    return 0;
}
