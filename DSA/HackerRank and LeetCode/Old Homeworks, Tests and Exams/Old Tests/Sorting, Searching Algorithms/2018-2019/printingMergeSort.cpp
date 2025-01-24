#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<int> arr1(n1), arr2(n2);
    
    for(int i = 0; i < n1; i++) {
        arr1[i] = arr[i + left];
    }
    
    for(int i = 0; i < n2; i++) {
        arr2[i] = arr[i + mid + 1];
    }
    
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if(arr1[i] < arr2[j]) {
            arr[k] = arr1[i];
            k++;
            i++;
        } else {
            arr[k] = arr2[j];
            k++;
            j++;
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
        for(int i = left; i <= right; i++ ){
            cout << arr[i] << ' ';
        }
    } else {
        cout << arr[left] << ' ';
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    return 0;
}
